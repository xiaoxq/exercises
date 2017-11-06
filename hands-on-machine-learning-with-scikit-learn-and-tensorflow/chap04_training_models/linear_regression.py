#!/usr/bin/env python3
"""Linear regression."""

import matplotlib.pyplot as plt
import numpy as np
from sklearn.linear_model import LinearRegression

if __name__ == '__main__':
    X = 2 * np.random.rand(100, 1)
    X_b = np.c_[np.ones((100, 1)), X]  # add x0 = 1 to each instance
    y = 4 + 3 * X + np.random.randn(100, 1)
    # Plot the regression within [0, 2]
    X_new = np.array([[0], [2]])

    # With numpy.
    theta_best = np.linalg.inv(X_b.T.dot(X_b)).dot(X_b.T).dot(y)
    X_new_b = np.c_[np.ones((2, 1)), X_new]
    y_predict1 = X_new_b.dot(theta_best)
    plt.subplot(121)
    plt.plot(X_new, y_predict1, "r-")
    plt.plot(X, y, "b.")
    plt.axis([0, 2, 0, 15])

    # With scipy.
    lin_reg = LinearRegression()
    lin_reg.fit(X, y)
    y_predict2 = lin_reg.predict(X_new)
    plt.subplot(122)
    plt.plot(X_new, y_predict2, "r-")
    plt.plot(X, y, "b.")
    plt.axis([0, 2, 0, 15])

    plt.show()
