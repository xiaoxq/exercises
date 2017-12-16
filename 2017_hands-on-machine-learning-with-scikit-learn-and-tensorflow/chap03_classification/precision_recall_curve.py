#!/usr/bin/env python3
"""Classifier which tests if an images is 5, plot precision and recall."""

from sklearn.linear_model import SGDClassifier
from sklearn.metrics import precision_recall_curve
from sklearn.model_selection import cross_val_predict
import matplotlib.pyplot as plt

import load_data


def plot_precision_recall_vs_threshold(precisions, recalls, thresholds):
    """Show precision_recall_curve."""
    plt.plot(thresholds, precisions[:-1], "b--", label="Precision")
    plt.plot(thresholds, recalls[:-1], "g-", label="Recall")
    plt.xlabel("Threshold")
    plt.legend(loc="upper left")
    plt.ylim([0, 1])

if __name__ == '__main__':
    train_data, train_label, _, _ = load_data.split_data()
    train_label_5 = (train_label == 5)

    sgd_clf = SGDClassifier(random_state=42)
    scores = cross_val_predict(sgd_clf, train_data, train_label_5, cv=3,
                               method="decision_function")
    precisions, recalls, thres = precision_recall_curve(train_label_5, scores)

    plot_precision_recall_vs_threshold(precisions, recalls, thres)
    plt.show()
