#!/usr/bin/env python3
"""Scikit learn random forest."""

from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_squared_error
from sklearn.model_selection import GridSearchCV
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
    param_grid = [
        {'n_estimators': [3, 10, 30], 'max_features': [2, 4, 6, 8]},
        {'bootstrap': [False], 'n_estimators': [3, 10],
         'max_features': [2, 3, 4]},
    ]

    forest_reg = RandomForestRegressor()
    grid_search = GridSearchCV(forest_reg, param_grid, cv=5,
                               scoring='neg_mean_squared_error')
    grid_search.fit(housing_training, label)

    # Evaluate
    housing, label = load_data.split_dataframe_column(test_set,
                                                      'median_house_value')
    housing_test = sklearn_feature_union.prepare_data(housing)
    predition = grid_search.best_estimator_.predict(housing_test)
    grid_mse = mean_squared_error(label, predition)
    grid_rmse = np.sqrt(grid_mse)
    print('Best params = {}'.format(grid_search.best_params_))
    print('root_mean_squared_error = {}'.format(grid_rmse))
    print('Prediction: {}'.format(predition[:5]))
    print('Label: {}'.format(list(label.iloc[:5])))


if __name__ == '__main__':
    main()
