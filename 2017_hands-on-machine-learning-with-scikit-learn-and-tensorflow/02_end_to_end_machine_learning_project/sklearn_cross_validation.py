#!/usr/bin/env python3
"""Scikit learn cross validation."""

from sklearn.model_selection import cross_val_score
from sklearn_pipeline import CombinedAttributesAdder
from sklearn.tree import DecisionTreeRegressor
import numpy as np

import load_data
import sklearn_feature_union


def main():
    """Main function."""
    training_set, test_set = load_data.split_train_and_test_set()
    housing, label = load_data.split_dataframe_column(training_set,
                                                      'median_house_value')
    CombinedAttributesAdder.compute_index(housing)

    housing_training = sklearn_feature_union.prepare_data(housing)

    # Train
    tree_reg = DecisionTreeRegressor()
    scores = cross_val_score(tree_reg, housing_training, label,
                             scoring="neg_mean_squared_error", cv=10)
    tree_rmse_scores = np.sqrt(-scores)

    def display_scores(scores):
        print("Scores:", scores)
        print("Mean:", scores.mean())
        print("Standard deviation:", scores.std())

    display_scores(tree_rmse_scores)


if __name__ == '__main__':
    main()
