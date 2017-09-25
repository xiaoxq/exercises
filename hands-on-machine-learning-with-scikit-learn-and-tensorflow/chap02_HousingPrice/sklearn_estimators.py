#!/usr/bin/env python3
"""Scikit learn estimators."""

import sklearn.preprocessing

import load_data

def main():
    """Main function."""
    training_set, _ = load_data.split_train_and_test_set()
    encoder = sklearn.preprocessing.LabelEncoder()
    housing_cat = training_set["ocean_proximity"]
    housing_cat_encoded = encoder.fit_transform(housing_cat)

    encoder = sklearn.preprocessing.OneHotEncoder()
    housing_cat_1hot = encoder.fit_transform(housing_cat_encoded.reshape(-1, 1))
    print(housing_cat_1hot.toarray())

if __name__ == '__main__':
    main()
