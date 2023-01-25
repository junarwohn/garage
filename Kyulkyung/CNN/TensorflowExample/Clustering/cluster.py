import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import random
import tensorflow as tf

orbit_arr = []
x_list = [2, 4]
y_list = [2, 4]
sign = [-1, 1]
for i in range(1000):
    orbit_arr.append(((x_list[(random.randrange(0, 2))] + sign[(random.randrange(0, 2))] * pow(random.random(), 2))
                      , (y_list[(random.randrange(0, 2))] + sign[(random.randrange(0, 2))] * pow(random.random(), 2))))

# df = pd.DataFrame({"x": [v[0] for v in orbit_arr], "y": [v[1] for v in orbit_arr]})
#
# sns.lmplot("x", "y", data=df, fit_reg=False, size=6)
# # plt.show()

vectors = tf.constant(orbit_arr)
k = 4
centroids = tf.Variable(tf.slice(tf.random_shuffle(vectors), [0, 0], [k, -1]))

expanded_vectors = tf.expand_dims(vectors, 0)
expanded_centroids = tf.expand_dims(centroids, 1)

assignments = tf.argmin(tf.reduce_sum(tf.square(tf.subtract(expanded_vectors, expanded_centroids)), 2), 0)

means = tf.concat([tf.reduce_mean(tf.gather(vectors, tf.reshape(tf.where(tf.equal(assignments, c)), [1, -1]))
                                  , reduction_indices=[1]) for c in range(k)], 0)

update_centroids = tf.assign(centroids, means)

init_op = tf.global_variables_initializer()

sess = tf.Session()
sess.run(init_op)

for step in range(100):
   _, centroid_values, assignment_values = sess.run([update_centroids, centroids, assignments])

data = {"x": [], "y": [], "cluster": []}

for i in range(len(assignment_values)):
    data["x"].append(orbit_arr[i][0])
    data["y"].append(orbit_arr[i][1])
    data["cluster"].append(assignment_values[i])

df = pd.DataFrame(data)
sns.lmplot("x", "y", data=df, fit_reg=False, size=6, hue="cluster", legend=False)
plt.show()
