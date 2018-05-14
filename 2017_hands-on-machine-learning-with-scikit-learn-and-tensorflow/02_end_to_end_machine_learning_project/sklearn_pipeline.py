#!/usr/bin/env python3
"""Scikit learn pipeline."""

from sklearn.base import BaseEstimator, TransformerMixin
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import Imputer, StandardScaler
import numpy as np

import load_data


class CombinedAttributesAdder(BaseEstimator, TransformerMixin):
    """CombinedAttributesAdder Estimator"""
    rooms_ix, bedrooms_ix, population_ix, household_ix = 3, 4, 5, 6

    def __init__(self, add_bedrooms_per_room = True): # no *args or **kargs
        self.add_bedrooms_per_room = add_bedrooms_per_room

    @classmethod
    def compute_index(cls, dataframe):
        """Compute index"""
        column_names = list(dataframe)
        cls.rooms_ix = column_names.index('total_rooms')
        cls.bedrooms_ix = column_names.index('total_bedrooms')
        cls.population_ix = column_names.index('population')
        cls.household_ix = column_names.index('households')

    def fit(self, X, y=None):
        """nothing else to do"""
        return self

    def transform(self, X, y=None):
        """
        Add rooms_per_household, population_per_household and probably
        bedrooms_per_room columns.
        """
        rooms_ix = self.rooms_ix
        bedrooms_ix = self.bedrooms_ix
        population_ix = self.population_ix
        household_ix = self.household_ix

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
    housing_num, _ = load_data.split_dataframe_column(training_set,
                                                      'ocean_proximity')
    CombinedAttributesAdder.compute_index(housing_num)
    num_pipeline = Pipeline([
        ('imputer', Imputer(strategy="median")),
        ('attribs_adder', CombinedAttributesAdder()),
        ('std_scaler', StandardScaler()),
    ])
    housing_num_tr = num_pipeline.fit_transform(housing_num)

    print(housing_num_tr)

if __name__ == '__main__':
    main()
