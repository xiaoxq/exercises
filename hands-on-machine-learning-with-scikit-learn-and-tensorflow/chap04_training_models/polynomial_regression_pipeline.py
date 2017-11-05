#!/usr/bin/env python3
"""Linear regression with polynomial regression pipeline."""

import matplotlib.pyplot as plt
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import PolynomialFeatures

if __name__ == '__main__':
    m = 100
    X = 6 * np.random.rand(m, 1) - 3
    y = 0.5 * X ** 2 + X + 2 + np.random.randn(m, 1)

    poly_reg = Pipeline([
        ("poly_features", PolynomialFeatures(degree=2, include_bias=False)),
        ("lin_reg", LinearRegression()),
    ])
    poly_reg.fit(X, y)

    X_sorted = X[X[:, 0].argsort()]
    y_predict = poly_reg.predict(X_sorted)

    plt.plot(X, y, "b.")
    plt.plot(X_sorted, y_predict, "r-")
    plt.show()
