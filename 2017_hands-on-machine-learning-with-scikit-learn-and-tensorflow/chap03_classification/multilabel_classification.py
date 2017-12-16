#!/usr/bin/env python3
"""KNeighborsClassifier"""

from sklearn.metrics import f1_score
from sklearn.model_selection import cross_val_predict
from sklearn.neighbors import KNeighborsClassifier
import numpy as np

import load_data


if __name__ == '__main__':
    train_data, train_label, _, _ = load_data.split_data()
    train_label_ge7 = (train_label >= 7)
    train_label_odd = (train_label % 2 == 1)
    multi_label = np.c_[train_label_ge7, train_label_odd]

    knn_clf = KNeighborsClassifier()
    knn_pred = cross_val_predict(knn_clf, train_data, multi_label, cv=3)
    print(f1_score(multi_label, knn_pred, average="macro"))
