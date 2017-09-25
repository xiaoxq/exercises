#!/usr/bin/env python3
"""Scikit learn pipeline."""

from sklearn.base import BaseEstimator, TransformerMixin
from sklearn.pipeline import Pipeline
import numpy as np
import sklearn.preprocessing as preprocessing

import load_data


class CombinedAttributesAdder(BaseEstimator, TransformerMixin):
    def __init__(self, add_bedrooms_per_room = True): # no *args or **kargs
        self.add_bedrooms_per_room = add_bedrooms_per_room

    def fit(self, X, y=None):
        """nothing else to do"""
        return self

    def transform(self, X, y=None):
        """
        Add rooms_per_household, population_per_household and probably
        bedrooms_per_room columns.
        """
        rooms_ix, bedrooms_ix, population_ix, household_ix = 3, 4, 5, 6

        rooms_per_household = X[:, rooms_ix] / X[:, household_ix]
        population_per_household = X[:, population_ix] / X[:, household_ix]
        if self.add_bedrooms_per_room:
            bedrooms_per_room = X[:, bedrooms_ix] / X[:, rooms_ix]
            return np.c_[X, rooms_per_household, population_per_household,
                         bedrooms_per_room]
        else:
            return np.c_[X, rooms_per_household, population_per_household]


def main():
    """Main function."""
    training_set, _ = load_data.split_train_and_test_set()
    housing_num = training_set.drop("ocean_proximity", axis=1)
    num_pipeline = Pipeline([
        ('imputer', preprocessing.Imputer(strategy="median")),
        ('attribs_adder', CombinedAttributesAdder()),
        ('std_scaler', preprocessing.StandardScaler()),
    ])
    housing_num_tr = num_pipeline.fit_transform(housing_num)

    print(housing_num_tr)

if __name__ == '__main__':
    main()
