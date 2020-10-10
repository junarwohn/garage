import numpy as np
import random
import matplotlib.pyplot as plt

g_exclude_data = 2

data = [
    [-2.9, 35.4], 
    [-2.1, 19.7], 
    [-0.9, 5.7], 
    [1.1,  2.1], 
    [0.1,  1.2], 
    [1.9, 8.7], 
    [3.1, 25.7], 
    [4.0, 41.5]
]


def calculate(coefficients, x):
    result = 0
    for i in range(len(coefficients)):
        result *= x
        result += coefficients[i]
    return result


def show_graph(coefficients, data=[]):
    x = np.linspace(-5, 5, 50)
    y = calculate(coefficients, x)
    fig = plt.figure()
    ax = fig.add_subplot(1, 1, 1)
    ax.spines['left'].set_position('center')
    ax.spines['bottom'].set_position('zero')
    ax.spines['right'].set_color('none')
    ax.spines['top'].set_color('none')
    ax.xaxis.set_ticks_position('bottom')
    ax.yaxis.set_ticks_position('left')
    # plot the function
    d = [[], []]
    for i, j in data:
        d[0].append(i)
        d[1].append(j)
    plt.scatter(d[0], d[1])
    plt.plot(x, y, 'r')
    # show the plot
    plt.show()


if __name__ == '__main__':
    for trial in range(0, 2):
        bitmap = [True for i in range(len(data))]
        cnt = 0
        while cnt != g_exclude_data:
            idx = random.randint(0, 7)
            if bitmap[idx]:
                bitmap[idx] = False
                cnt += 1

        selected_data = [e for i, e in enumerate(data) if bitmap[i]]

        A = np.array([
            [x*x, x, 1] for x, y in selected_data
        ])

        b = np.array([
            y for x, y in selected_data
        ])
        X = np.linalg.pinv(A.T @ A)
        X = X @ A.T @ b.T
        print(X)
        show_graph(X, selected_data)
