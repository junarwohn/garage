from __future__ import absolute_import, print_function

import tvm
from tvm import te
import numpy as np

# declare some variable for use later
n = te.var('n')
m = te.var('m')

#########################################
# C = A[i, j] * B[i, j]

# declare a matrix element-wise multiply
A = te.placeholder((m, n), name='A')
B = te.placeholder((m, n), name='B')
C = te.compute((m, n), lambda i, j: A[i, j] * B[i, j], name='C')

s = te.create_schedule([C.op])
# lower will transform the computation from definition to the real
# callable function. With argument `simple_mode=True`, it will
# return you a readable C like statement, we use it here to print the
# schedule result.
print(tvm.lower(s, [A, B, C], simple_mode=True))

#########################################
# B = A[i] * 2

A = te.placeholder((m,), name='A')
B = te.compute((m,), lambda i: A[i] * 2, name='B')

s = te.create_schedule(B.op)
xo, xi = s[B].split(B.op.axis[0], factor=32)
print(tvm.lower(s, [A, B], simple_mode=True))

#########################################
# B = A[i]

A = te.placeholder((m,), name='A')
B = te.compute((m,), lambda i: A[i], name='B')

s = te.create_schedule(B.op)
bx, tx = s[B].split(B.op.axis[0], nparts=32)
print(tvm.lower(s, [A, B], simple_mode=True))

#########################################
# B = A[i, j]

A = te.placeholder((m, n), name='A')
B = te.compute((m, n), lambda i, j: A[i, j], name='B')

s = te.create_schedule(B.op)
xo, yo, xi, yi = s[B].tile(B.op.axis[0], B.op.axis[1], x_factor=10, y_factor=5)
fused = s[B].fuse(xi, yi)
print(tvm.lower(s, [A, B], simple_mode=True))

A = te.placeholder((m, n), name='A')
B = te.compute((m, n), lambda i, j: A[i, j], name='B')

s = te.create_schedule(B.op)
# tile to four axes first: (i.outer, j.outer, j.inner)
xo, yo, xi, yi = s[B].tile(B.op.axis[0], B.op.axis[1], x_factor=10, y_factor=5)
# then fuse (i.inner, j.inner) into one axis: (i.inner.j.inner.fused)
fused = s[B].reorder(xi, yi)
print(tvm.lower(s, [A, B], simple_mode=True))

A = te.placeholder((n,), name='A')
B = te.compute(A.shape, lambda i: A[i] * 2, name='B')

s = te.create_schedule(B.op)
bx, tx = s[B].split(B.op.axis[0], factor=64)
s[B].bind(bx, te.thread_axis('blockIdx.x'))
s[B].bind(tx, te.thread_axis('threadIdx.x'))
print(tvm.lower(s, [A, B], simple_mode=True))
