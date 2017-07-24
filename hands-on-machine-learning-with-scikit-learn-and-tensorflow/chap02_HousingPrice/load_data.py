#!/usr/bin/env python
"""Load data."""

import os
import pandas as pd

DATA_DIR = os.path.join(os.path.dirname(__file__), '../data')


def load_housing_data():
    """Load housing.csv data."""
    csv_path = os.path.join(DATA_DIR, "handson-ml/datasets/housing/housing.csv")
    return pd.read_csv(csv_path)
