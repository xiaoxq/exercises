#!/usr/bin/env python3
"""Scikit learn random forest."""

from sklearn.ensemble import RandomForestRegressor
from sklearn.model_selection import cross_val_score
from sklearn_pipeline import CombinedAttributesAdder
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
    forest_reg = RandomForestRegressor()
    scores = cross_val_score(forest_reg, housing_training, label,
                             scoring="neg_mean_squared_error", cv=10)
    forest_rmse_scores = np.sqrt(-scores)

    def display_scores(scores):
        print("Scores:", scores)
        print("Mean:", scores.mean())
        print("Standard deviation:", scores.std())

    display_scores(forest_rmse_scores)


if __name__ == '__main__':
    main()
