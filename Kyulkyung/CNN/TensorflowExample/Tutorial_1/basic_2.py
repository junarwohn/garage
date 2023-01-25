import tensorflow as tf
import numpy as np
# Reduce_mean
# calculates the mean of an array.
b = tf.Variable([10, 20, 30, 40, 50, 60], name='t')
with tf.Session() as sess:
    # sess.run(tf.initialize_all_variables())
    # WARNING: tensorflow:From
    # \tensorflow\lib\site - packages\tensorflow\python\util\tf_
    # should_use.py: 175: initialize_all_variables(from tensorflow.python.ops.variables)
    # is deprecated and will be removed after 2017 - 03 - 02.
    # Instructions for updating: Use `tf.global_variables_initializer` instead.
    sess.run(tf.global_variables_initializer())
    print(sess.run(tf.reduce_mean(b)))

# ArgMax
# Very similar to python argmax. Gets you the maximum value from a tensor along the specified axis.
a = [[0.1, 0.2, 0.3],
     [20, 2, 3],
     [50, 60, 55]
     ]
b = tf.Variable(a, name='b')
with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())
    print(sess.run(tf.argmax(b, 1)))


# Linear Regression Exercise:
# a) Creating training data:
trainX = np.linspace(-1, 1, 101)
trainY = 3 * trainX + np.random.randn(*trainX.shape) * 0.33
# b) Placeholders:
X = tf.placeholder("float")
Y = tf.placeholder("float")
# c) Modeling:
w = tf.Variable(0.0, name="weights")
y_model = tf.multiply(X, w)

cost = (tf.pow(Y-y_model, 2))
train_op = tf.train.GradientDescentOptimizer(0.01).minimize(cost)
# d) Training:
# Please note that, first thing that has been done is to initialize the variables by calling init inside session.run().
# Later we run train_op by feeding feed_dict.
# Finally, we print the value of w(again inside sess.run() which should be around 3.
init = tf.global_variables_initializer()
with tf.Session as sess:
    sess.run(init)
    for i in range(100):
        for (x,y) in zip(trainX, trainY):
            sess.run(train_op, feed_dict={X: x, Y: y})
    print(sess.run(w))
# e) Exercise:
# If you create a new session block after this code and try to print w, what will be the output?
with tf.Session as sess:
    sess.run(init)
    print(sess.run(w))
