import numpy as np
import tvm
from tvm import te
import tvm.relay as relay

# Create An Example Relay Program
def example():
    shape = (1, 64, 54, 54)
    c_data = np.empty(shape).astype('float32')
    c = relay.const(c_data)
    weight = relay.var('weight', shape=(64, 64, 3, 3))
    x = relay.var('x', relay.TensorType((1, 64, 56, 56), 'float32'))
    conv = relay.nn.conv2d(x, weight)
    y = relay.add(c, c)
    y = relay.multiply(y, relay.const(2, 'float32'))
    y = relay.add(conv, y)
    z = relay.add(y, c)
    z1 = relay.add(y, c)
    z2 = relay.add(z, z1)
    return relay.Function([x, weight], z2)

# Optimize the Program

f = example()
mod = tvm.IRModule.from_expr(f)
print(mod)

fold_const = relay.transform.FoldConstant()
mod = fold_const(mod)
mod = relay.transform.EliminateCommonSubexpr()(mod)
mod = relay.transform.FuseOps(fuse_opt_level=2)(mod)
print(mod)

print('done')
