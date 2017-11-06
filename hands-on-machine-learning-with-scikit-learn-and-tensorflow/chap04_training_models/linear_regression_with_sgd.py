#!/usr/bin/env python3
"""Linear regression with sgd."""

import matplotlib.pyplot as plt
import numpy as np
from sklearn.linear_model import SGDRegressor

if __name__ == '__main__':
    X = 2 * np.random.rand(100, 1)
    X_b = np.c_[np.ones((100, 1)), X]  # add x0 = 1 to each instance
    y = 4 + 3 * X + np.random.randn(100, 1)
    # Plot the regression within [0, 2]
    X_new = np.array([[0], [2]])

    # With numpy
    def learning_schedule(t, t0=5.0, t1=50.0): return t0 / (t + t1)

    n_epochs = 50
    m = 100
    theta = np.random.randn(2, 1)  # random initialization
    for epoch in range(n_epochs):
        for i in range(m):
            random_index = np.random.randint(m)
            xi = X_b[random_index:random_index + 1]
            yi = y[random_index:random_index + 1]
            gradients = 2 * xi.T.dot(xi.dot(theta) - yi)
            eta = learning_schedule(epoch * m + i)
            theta = theta - eta * gradients
    X_new_b = np.c_[np.ones((2, 1)), X_new]
    y_predict1 = X_new_b.dot(theta)

    plt.subplot(121)
    plt.plot(X_new_b, y_predict1, "r-")
    plt.plot(X, y, "b.")
    plt.axis([0, 2, 0, 15])

    # With scipy.
    sgd_reg = SGDRegressor(n_iter=50, penalty=None, eta0=0.1)
    sgd_reg.fit(X, y.ravel())
    y_predict2 = sgd_reg.predict(X_new)

    plt.subplot(122)
    plt.plot(X_new, y_predict2, "r-")
    plt.plot(X, y, "b.")
    plt.axis([0, 2, 0, 15])

    plt.show()
