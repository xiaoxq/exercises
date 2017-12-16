#!/usr/bin/env python3
"""Elastic net."""

import matplotlib.pyplot as plt
import numpy as np
from sklearn.linear_model import ElasticNet
from sklearn.linear_model import Lasso
from sklearn.preprocessing import PolynomialFeatures

if __name__ == '__main__':
    m = 100
    X = 6 * np.random.rand(m, 1) - 3
    y = 0.5 * X ** 2 + X + 2 + np.random.randn(m, 1)

    poly_features = PolynomialFeatures(degree=2, include_bias=False)
    X_poly = poly_features.fit_transform(X)
    X_sorted = X_poly[X_poly[:, 0].argsort()]

    # Lasso.
    lasso_reg = Lasso(alpha=0.1)
    lasso_reg.fit(X_poly, y)
    y_predict = lasso_reg.predict(X_sorted)
    plt.subplot(121)
    plt.plot(X, y, "b.")
    plt.plot(X_sorted[:,0], y_predict, "r-")

    # Elastic net.
    elastic_net = ElasticNet(alpha=0.1, l1_ratio=0.5)
    elastic_net.fit(X_poly, y)
    y_predict = elastic_net.predict(X_sorted)
    plt.subplot(122)
    plt.plot(X, y, "b.")
    plt.plot(X_sorted[:,0], y_predict, "r-")

    plt.show()
