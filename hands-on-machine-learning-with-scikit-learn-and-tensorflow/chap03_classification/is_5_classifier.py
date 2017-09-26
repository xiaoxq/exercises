#!/usr/bin/env python3
"""Classifier which tests if an images is 5."""

from sklearn.linear_model import SGDClassifier
import numpy as np

import load_data


if __name__ == '__main__':
    train_data, train_label, test_data, test_label = load_data.split_data()
    train_label_5 = (train_label == 5)
    test_label_5 = (test_label == 5)

    sgd_clf = SGDClassifier(random_state=42)
    sgd_clf.fit(train_data, train_label_5)

    prediction = sgd_clf.predict(test_data)
    prediction_count = sum(prediction)
    correct = np.logical_and(prediction, test_label_5)
    correct_count = sum(correct)
    ground_truth_count = sum(test_label_5)

    print('Precision: {}/{} = {}'.format(
        correct_count, prediction_count, correct_count * 1.0 / prediction_count))
    print('Recall: {}/{} = {}'.format(
        correct_count, ground_truth_count, correct_count * 1.0 / ground_truth_count))
