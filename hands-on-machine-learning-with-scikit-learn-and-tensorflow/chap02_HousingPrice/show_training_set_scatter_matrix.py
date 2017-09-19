#!/usr/bin/env python3
"""Show training_set geo scatter plot."""

import matplotlib.pyplot as plt
import pandas

import load_data


def main():
    """Main function."""
    training_set, _ = load_data.split_train_and_test_set()
    cols = [
        "median_house_value",
        "median_income",
        "total_rooms",
        "housing_median_age",
    ]
    pandas.plotting.scatter_matrix(training_set[cols], figsize=(12, 8))
    plt.show()

if __name__ == '__main__':
    main()
