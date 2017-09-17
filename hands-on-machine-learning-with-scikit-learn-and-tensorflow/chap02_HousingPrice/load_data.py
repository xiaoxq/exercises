#!/usr/bin/env python3
"""Load data."""

import os

import numpy as np
import pandas as pd
from sklearn.model_selection import StratifiedShuffleSplit

DATA_DIR = os.path.join(os.path.dirname(__file__), '../data')


def load_housing_data():
    """Load housing.csv data."""
    csv_path = os.path.join(DATA_DIR, "handson-ml/datasets/housing/housing.csv")
    return pd.read_csv(csv_path)


def load_housing_data_with_income_cat():
    """Load housing data and add income_cat field."""
    housing = load_housing_data()
    income_cat = np.ceil(housing["median_income"] / 1.5)
    income_cat.where(income_cat > 5, 5.0, inplace=True)
    return housing, income_cat


def split_train_and_test_set():
    """Split housing data to training and testing test based on income_cat"""
    housing, income_cat = load_housing_data_with_income_cat()
    split = StratifiedShuffleSplit(n_splits=1, test_size=0.2, random_state=42)
    for train_index, test_index in split.split(housing, income_cat):
        strat_train_set = housing.loc[train_index]
        strat_test_set = housing.loc[test_index]
        # Actually we do only one split.
        break
    return strat_train_set, strat_test_set
