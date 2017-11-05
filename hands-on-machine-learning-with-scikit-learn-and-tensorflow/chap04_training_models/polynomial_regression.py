#!/usr/bin/env python3
"""Linear regression with polynomial regression."""

import matplotlib.pyplot as plt
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures

if __name__ == '__main__':
    m = 100
    X = 6 * np.random.rand(m, 1) - 3
    y = 0.5 * X ** 2 + X + 2 + np.random.randn(m, 1)

    poly_features = PolynomialFeatures(degree=2, include_bias=False)
    X_poly = poly_features.fit_transform(X)

    lin_reg = LinearRegression()
    lin_reg.fit(X_poly, y)

    X_sorted = X_poly[X_poly[:, 0].argsort()]
    y_predict = lin_reg.predict(X_sorted)

    plt.plot(X, y, "b.")
    plt.plot(X_sorted[:,0], y_predict, "r-")
    plt.show()
