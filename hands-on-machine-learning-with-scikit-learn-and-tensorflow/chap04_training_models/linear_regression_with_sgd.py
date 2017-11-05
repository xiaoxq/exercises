#!/usr/bin/env python3
"""Linear regression with sgd."""

import matplotlib.pyplot as plt
import numpy as np

if __name__ == '__main__':
    X = 2 * np.random.rand(100, 1)
    X_b = np.c_[np.ones((100, 1)), X]  # add x0 = 1 to each instance
    y = 4 + 3 * X + np.random.randn(100, 1)

    X_new = np.array([[0], [2]])
    X_new_b = np.c_[np.ones((2, 1)), X_new]

    n_epochs = 50
    m = 100

    def learning_schedule(t, t0 = 5, t1 = 50):
        return t0 / (t + t1)

    theta = np.random.randn(2, 1)  # random initialization
    for epoch in range(n_epochs):
        for i in range(m):
            random_index = np.random.randint(m)
            xi = X_b[random_index:random_index + 1]
            yi = y[random_index:random_index + 1]
            gradients = 2 * xi.T.dot(xi.dot(theta) - yi)
            eta = learning_schedule(epoch * m + i)
            theta = theta - eta * gradients
        y_predict = X_new_b.dot(theta)
        plt.plot(X_new_b, y_predict, "r-")

    plt.plot(X, y, "b.")
    plt.axis([0, 2, 0, 15])
    plt.show()
