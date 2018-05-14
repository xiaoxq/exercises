#!/usr/bin/env python3
"""Scikit learn decision tree model."""

from sklearn.metrics import mean_squared_error
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
    tree_reg.fit(housing_training, label)

    # Evaluate on training data to see the over fitting.
    # housing, label = load_data.split_dataframe_column(test_set,
    #                                                   'median_house_value')
    housing_test = sklearn_feature_union.prepare_data(housing)
    predition = tree_reg.predict(housing_test)
    tree_mse = mean_squared_error(label, predition)
    tree_rmse = np.sqrt(tree_mse)
    print('root_mean_squared_error = {}'.format(tree_rmse))

if __name__ == '__main__':
    main()
