#!/usr/bin/env python3
"""Scikit learn linear model."""

from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error
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
    lin_reg = LinearRegression()
    lin_reg.fit(housing_training, label)

    # Evaluate
    housing, label = load_data.split_dataframe_column(test_set,
                                                      'median_house_value')
    housing_test = sklearn_feature_union.prepare_data(housing)
    predition = lin_reg.predict(housing_test)
    lin_mse = mean_squared_error(label, predition)
    lin_rmse = np.sqrt(lin_mse)
    print('root_mean_squared_error = {}'.format(lin_rmse))


if __name__ == '__main__':
    main()
