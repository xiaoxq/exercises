#!/usr/bin/env python3
"""Linear regression with numpy."""

import matplotlib.pyplot as plt
import numpy as np

if __name__ == '__main__':
    X = 2 * np.random.rand(100, 1)
    X_b = np.c_[np.ones((100, 1)), X]  # add x0 = 1 to each instance
    y = 4 + 3 * X + np.random.randn(100, 1)

    theta_best = np.linalg.inv(X_b.T.dot(X_b)).dot(X_b.T).dot(y)
    print('theta_best = {}'.format(theta_best))

    # Plot the regression within [0, 2]
    X_new = np.array([[0], [2]])
    X_new_b = np.c_[np.ones((2, 1)), X_new]
    y_predict = X_new_b.dot(theta_best)

    plt.plot(X_new, y_predict, "r-")
    plt.plot(X, y, "b.")
    plt.axis([0, 2, 0, 15])
    plt.show()
