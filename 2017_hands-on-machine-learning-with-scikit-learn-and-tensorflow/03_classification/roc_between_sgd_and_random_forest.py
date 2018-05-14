#!/usr/bin/env python3
"""Classifier which tests if an images is 5, plot sgd and random forest ROC."""

from sklearn.ensemble import RandomForestClassifier
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
    sgd_scores = cross_val_predict(sgd_clf, train_data, train_label_5, cv=3,
                                   method="decision_function")
    sgd_fpr, sgd_tpr, _ = roc_curve(train_label_5, sgd_scores)
    print('sgd_roc_auc_score = {}'.format(
        roc_auc_score(train_label_5, sgd_scores)))
    plot_roc_curve(sgd_fpr, sgd_tpr, 'SGD')

    forest_clf = RandomForestClassifier(random_state=42)
    forest_probas = cross_val_predict(forest_clf, train_data, train_label_5,
                                      cv=3, method="predict_proba")
    forest_scores = forest_probas[:, 1]
    forest_fpr, forest_tpr, _ = roc_curve(train_label_5, forest_scores)
    print('forest_roc_auc_score = {}'.format(
        roc_auc_score(train_label_5, forest_scores)))
    plot_roc_curve(forest_fpr, forest_tpr, 'Forest')

    plt.legend(loc="bottom right")
    plt.show()
