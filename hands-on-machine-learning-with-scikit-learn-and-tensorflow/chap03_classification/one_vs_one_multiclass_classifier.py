#!/usr/bin/env python3
"""One-vs-one classifier."""

from sklearn.linear_model import SGDClassifier
from sklearn.model_selection import cross_val_score
from sklearn.multiclass import OneVsOneClassifier
from sklearn.preprocessing import StandardScaler
import numpy as np

import load_data


if __name__ == '__main__':
    train_data, train_label, test_data, test_label = load_data.split_data()
    ovo_clf = OneVsOneClassifier(SGDClassifier(random_state=42))
    print(cross_val_score(
        ovo_clf, train_data, train_label, cv=3, scoring="accuracy"))

    scaler = StandardScaler()
    train_data_scaled = scaler.fit_transform(train_data.astype(np.float64))
    print('After scaled: {}'.format(cross_val_score(
        ovo_clf, train_data_scaled, train_label, cv=3, scoring="accuracy")))
