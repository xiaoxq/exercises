#!/usr/bin/env python3
"""Logistic regression."""

import matplotlib.pyplot as plt
import numpy as np
from sklearn import datasets
from sklearn.linear_model import LogisticRegression

if __name__ == '__main__':
    iris = datasets.load_iris()
    print(list(iris.keys()))
    X = iris["data"][:, 3:]  # petal width
    y = (iris["target"] == 2).astype(np.int)  # 1 if Iris-Virginica, else 0
    log_reg = LogisticRegression()
    log_reg.fit(X, y)

    X_new = np.linspace(0, 3, 1000).reshape(-1, 1)
    y_proba = log_reg.predict_proba(X_new)
    plt.plot(X_new, y_proba[:, 1], "g-", label="Iris-Virginica")
    plt.plot(X_new, y_proba[:, 0], "b--", label="Not Iris-Virginica")
    plt.show()
