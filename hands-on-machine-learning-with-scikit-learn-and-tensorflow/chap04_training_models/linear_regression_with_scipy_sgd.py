#!/usr/bin/env python3
"""Linear regression with scipy sgd."""

import matplotlib.pyplot as plt
import numpy as np
from sklearn.linear_model import SGDRegressor

if __name__ == '__main__':
    X = 2 * np.random.rand(100, 1)
    y = 4 + 3 * X + np.random.randn(100, 1)

    # Plot the regression within [0, 2]
    X_new = np.array([[0], [2]])

    sgd_reg = SGDRegressor(n_iter=50, penalty=None, eta0=0.1)
    sgd_reg.fit(X, y.ravel())
    y_predict = sgd_reg.predict(X_new)

    plt.plot(X_new, y_predict, "r-")
    plt.plot(X, y, "b.")
    plt.axis([0, 2, 0, 15])
    plt.show()
