#!/usr/bin/env python3
"""Linear regression with numpy."""

import matplotlib.pyplot as plt
import numpy as np
from sklearn.linear_model import LinearRegression

if __name__ == '__main__':
    X = 2 * np.random.rand(100, 1)
    X_b = np.c_[np.ones((100, 1)), X]  # add x0 = 1 to each instance
    y = 4 + 3 * X + np.random.randn(100, 1)

    # Plot the regression within [0, 2]
    X_new = np.array([[0], [2]])
    X_new_b = np.c_[np.ones((2, 1)), X_new]

    lin_reg = LinearRegression()
    lin_reg.fit(X, y)
    y_predict = lin_reg.predict(X_new_b)

    plt.plot(X_new, y_predict, "r-")
    plt.plot(X, y, "b.")
    plt.axis([0, 2, 0, 15])
    plt.show()
