#!/usr/bin/env python3
"""Scikit learn pipeline."""

from sklearn.base import BaseEstimator, TransformerMixin
from sklearn.pipeline import FeatureUnion, Pipeline
from sklearn.preprocessing import Imputer, LabelBinarizer, StandardScaler

import load_data
import sklearn_pipeline


class DataFrameSelector(BaseEstimator, TransformerMixin):
    """DataFrameSelector Estimator"""

    def __init__(self, attribute_names):
        self.attribute_names = attribute_names

    def fit(self, X, y=None):
        """Do nothing."""
        return self

    def transform(self, X):
        """Select value by addtribute names."""
        return X[self.attribute_names].values


def prepare_data(data_set):
    """Prepare training data."""
    num_attribs = list(data_set)
    num_attribs.remove('ocean_proximity')
    cat_attribs = ['ocean_proximity']

    num_pipeline = Pipeline([
        ('selector', DataFrameSelector(num_attribs)),
        ('imputer', Imputer(strategy="median")),
        ('attribs_adder', sklearn_pipeline.CombinedAttributesAdder()),
        ('std_scaler', StandardScaler()),
    ])

    cat_pipeline = Pipeline([
        ('selector', DataFrameSelector(cat_attribs)),
        ('label_binarizer', LabelBinarizer()),
    ])

    full_pipeline = FeatureUnion(transformer_list=[
        ("num_pipeline", num_pipeline),
        ("cat_pipeline", cat_pipeline),
    ])

    return full_pipeline.fit_transform(data_set)


def main():
    """Main function."""
    training_set, _ = load_data.split_train_and_test_set()
    housing_prepared = prepare_data(training_set)
    print(housing_prepared)
    print(housing_prepared.shape)

if __name__ == '__main__':
    main()
