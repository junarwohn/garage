# From https://www.tensorflow.org/get_started/get_started
import tensorflow as tf

import random
import time
a = random.randint(0, 10)
b_ = random.randint(0, 10)
for i in range(5) :
    x_ = random.randint(0, 10)
    print(str(x_) + " : " + str(a * x_ + b_))




# Model parameters
W = tf.Variable([.3], tf.float32)
b = tf.Variable([-.3], tf.float32)

# Model input and output
x = tf.placeholder(tf.float32)
y = tf.placeholder(tf.float32)

linear_model = x * W + b

# cost/loss function
loss = tf.reduce_sum(tf.square(linear_model - y))  # sum of the squares

# optimizer
optimizer = tf.train.GradientDescentOptimizer(0.01)
train = optimizer.minimize(loss)

# training data
x_train = []
y_train = []

for i in range(5) :
    x_ = random.randint(0, 10)
    x_train.append(x_)
    y_train.append(a * x_ + b_)

# training loop
init = tf.global_variables_initializer()
sess = tf.Session()
sess.run(init)  # reset values to wrong
for i in range(2000):
    sess.run(train, {x: x_train, y: y_train})

# evaluate training accuracy
curr_W, curr_b, curr_loss = sess.run([W, b, loss], {x: x_train, y: y_train})
# print("W: %s b: %s loss: %s" % (curr_W, curr_b, curr_loss))

t_end = time.time() + 10;
score = 0
trial = 0
while time.time() < t_end:
    q_x = random.randint(0, 20)
    answer = a * q_x + b
    trial = trial + 1
    # print(str(q_x) + "?\n")
    submit = curr_W * q_x + curr_b
    if answer == submit :
        score = score + 1
print(a , b_)
print(trial)
print(score)
