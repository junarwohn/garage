import numpy as np
from tensorflow.keras import datasets, layers, models

import tvm
from tvm import te
import tvm.relay as relay
from tvm.contrib.download import download_testdata
import keras
import numpy as np
import tensorflow as tf
from PIL import Image
from tvm.contrib.download import download_testdata
from SimpleModelKeras import Net

import tensorflow as tf
from tensorflow.keras import datasets, layers, models
import keras


# def Net(shape):
#     input_layer = layers.Input(shape=shape)
#     out = layers.Conv2D(filters=16, kernel_size=3, strides=1, padding='same')(input_layer)
#     out = layers.MaxPool2D(pool_size=(2,2), strides=2, padding='same')(out)
#     # out = layers.Conv2D(filters=32, kernel_size=3, strides=1, padding='same')(out)
#     # out = layers.MaxPool2D(pool_size=(2,2), strides=2, padding='same')(out)
#     # out = layers.Conv2D(filters=64, kernel_size=3, strides=1, padding='same')(out)
#     # out = layers.MaxPool2D(pool_size=(2,2), strides=2, padding='same')(out)
#     # out = layers.Conv2D(filters=128, kernel_size=3, strides=1, padding='same')(out)
#     # out = layers.MaxPool2D(pool_size=(2,2), strides=2, padding='same')(out)
#     model = keras.models.Model(inputs=input_layer, outputs=out)
#     return model

img_url = "https://github.com/dmlc/mxnet.js/blob/main/data/cat.png?raw=true"
img_path = download_testdata(img_url, "cat.png", module="data")
img = Image.open(img_path).resize((256,256))

model = Net((256,256,3))
data = np.array(img)[np.newaxis, :].astype("float32").transpose([0, 3, 1, 2])

shape_dict = {"input_1": data.shape}
mod, params = relay.frontend.from_keras(model, shape_dict)
print(mod.astext(show_meta_data=False))

# compile the model
target = "cuda"
dev = tvm.cuda(0)

with tvm.transform.PassContext(opt_level=3):
    lib = relay.build(mod, target, params=params)
# print(lib.get_graph_json())

with tvm.transform.PassContext(opt_level=3):
    executor = relay.build_module.create_executor("graph", mod, dev, target)
    
dtype = "float32"
tvm_out = executor.evaluate()(tvm.nd.array(data.astype(dtype)), **params)
