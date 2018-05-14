#!/usr/bin/env python3
"""Confusion_matrix plotting."""

from sklearn.linear_model import SGDClassifier
from sklearn.model_selection import cross_val_predict
from sklearn.metrics import confusion_matrix
from sklearn.preprocessing import StandardScaler
import matplotlib.pyplot as plt
import numpy as np

import load_data


if __name__ == '__main__':
    train_data, train_label, _, _ = load_data.split_data()
    scaler = StandardScaler()
    train_data_scaled = scaler.fit_transform(train_data.astype(np.float64))

    sgd_clf = SGDClassifier(random_state=42)
    predict = cross_val_predict(sgd_clf, train_data_scaled, train_label, cv=3)
    conf_mx = confusion_matrix(train_label, predict)

    row_sums = conf_mx.sum(axis=1, keepdims=True)
    norm_conf_mx = conf_mx / row_sums
    np.fill_diagonal(norm_conf_mx, 0)

    plt.matshow(norm_conf_mx, cmap=plt.cm.gray)
    plt.show()
