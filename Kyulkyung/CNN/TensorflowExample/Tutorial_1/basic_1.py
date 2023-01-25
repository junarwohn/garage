# http://cv-tricks.com/artificial-intelligence/deep-learning/deep-learning-frameworks/tensorflow/tensorflow-tutorial/

import tensorflow as tf

graph = tf.get_default_graph()

print(graph.get_operations())

for op in graph.get_operations():
    print(op.name)
# A graph is used to define operations, but the operations are only run within a session.

# Constants
# you can’t print/access constant a unless you run it inside a session

a = tf.constant(1.0)
print(a)
with tf.Session() as sess:
    print(sess.run(a))
    print(a)

# Variables
# are again Tensors which are like variables in any other language.

b = tf.Variable(2.0, name="text_var")
print(b)
with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())
    print(sess.run(b))

graph = tf.get_default_graph()
for op in graph.get_operations():
    print(op.name)

# Placeholders
# are tensors which are waiting to be initialized/fed.
# Placeholders are used for training data which is only fed when the code is actually run inside a session.

a = tf.placeholder("float")
b = tf.placeholder("float")
y = tf.multiply(a, b)
feed_dict = {a: 2, b: 3}
with tf.Session() as sess:
    print(sess.run(y, feed_dict))

# if two variable type is different
a = tf.placeholder("int32")
b = tf.placeholder("float")
a = tf.cast(a, tf.float32)
y = tf.multiply(a, b)
feed_dict = {a: 2, b: 3}
with tf.Session() as sess:
    print(sess.run(y, feed_dict))
