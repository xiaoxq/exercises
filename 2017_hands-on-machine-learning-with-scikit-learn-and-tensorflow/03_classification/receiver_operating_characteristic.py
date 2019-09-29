#!/usr/bin/env python3
"""Classifier which tests if an images is 5, plot ROC."""

from sklearn.linear_model import SGDClassifier
from sklearn.metrics import roc_curve, roc_auc_score
from sklearn.model_selection import cross_val_predict
import matplotlib.pyplot as plt

import load_data


def plot_roc_curve(fpr, tpr, label=None):
    plt.plot(fpr, tpr, linewidth=2, label=label)
    plt.plot([0, 1], [0, 1], 'k--')
    plt.axis([0, 1, 0, 1])
    plt.xlabel('False Positive Rate')
    plt.ylabel('True Positive Rate')


if __name__ == '__main__':
    train_data, train_label, _, _ = load_data.split_data()
    train_label_5 = (train_label == 5)

    sgd_clf = SGDClassifier(random_state=42)
    scores = cross_val_predict(sgd_clf, train_data, train_label_5, cv=3,
                               method="decision_function")
    print('roc_auc_score = {}'.format(roc_auc_score(train_label_5, scores)))

    fpr, tpr, _ = roc_curve(train_label_5, scores)
    plot_roc_curve(fpr, tpr)
    plt.show()
