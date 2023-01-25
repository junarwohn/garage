import numpy as np

from tvm import relay
from tvm.relay import testing
import tvm
from tvm import te
from tvm.contrib import graph_executor
import tvm.testing

batch_size = 1
num_class = 1000
image_shape = (3, 224, 224)
data_shape = (batch_size,) + image_shape
out_shape = (batch_size, num_class)

mod, params = relay.testing.vgg.get_workload(
    num_layers=16, batch_size=batch_size, image_shape=image_shape
    )

# print("mod astext")
# print(mod.astext(show_meta_data=False))



opt_level = 3
# opt_level = 1
target = tvm.target.cuda()
with tvm.transform.PassContext(opt_level=opt_level):
    lib = relay.build(mod, target, params=params)

# create random input
dev = tvm.cuda()
data = np.random.uniform(-1, 1, size=data_shape).astype('float32')
# print("shape of input data :", data.shape)

# create module
module = graph_executor.GraphModule(lib['default'](dev))

# set input and parameter
module.set_input('data', data)

# run
module.run()

# get output
out = module.get_output(0, tvm.nd.empty(out_shape)).asnumpy()

# print first 10 elements of output
# print(out.flatten()[0:10])

from tvm.contrib import utils

temp = utils.tempdir()
path_lib = temp.relpath('deploy_lib.tar')
lib.export_library(path_lib)
# print(temp.listdir())

# load the module back.
loaded_lib = tvm.runtime.load_module(path_lib)
input_data = tvm.nd.array(data)

module = graph_executor.GraphModule(loaded_lib['default'](dev))
module.run(data=input_data)
out_deploy = module.get_output(0).asnumpy()
print(lib.get_graph_json())
# print first 10 elements of output
# print(out_deploy.flatten()[0:10])

# check whether the output from deployed module is consistent with original one
tvm.testing.assert_allclose(out_deploy, out, atol=1e-5)
