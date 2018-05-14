#!/usr/bin/env python3
"""Classifier which tests if an images is 5."""

from sklearn.linear_model import SGDClassifier
from sklearn.metrics import confusion_matrix, f1_score, precision_score, recall_score

import load_data


def print_scores(label, predicted):
    """Fine print score."""
    mat = confusion_matrix(label, predicted)
    print('\tTrue Negative: \t {}'.format(mat[0,0]))
    print('\tFalse Positive:\t {}'.format(mat[0,1]))
    print('\tFalse Negative:\t {}'.format(mat[1,0]))
    print('\tTrue Positive: \t {}'.format(mat[1,1]))

    print('\tPrecision:\t {}'.format(precision_score(label, predicted)))
    print('\tRecall:   \t {}'.format(recall_score(label, predicted)))
    print('\tF1:       \t {}'.format(f1_score(label, predicted)))

if __name__ == '__main__':
    train_data, train_label, test_data, test_label = load_data.split_data()
    train_label_5 = (train_label == 5)
    test_label_5 = (test_label == 5)

    sgd_clf = SGDClassifier(random_state=42)
    sgd_clf.fit(train_data, train_label_5)

    print('training confusion_matrix:')
    print_scores(train_label_5, sgd_clf.predict(train_data))

    print('testing confusion_matrix:')
    print_scores(test_label_5, sgd_clf.predict(test_data))
