#!/usr/bin/env python3
"""Add attribute combinations."""

import load_data


def main():
    """Main function."""
    training_set, _ = load_data.split_train_and_test_set()
    training_set["rooms_per_household"] = (
        training_set["total_rooms"] / training_set["households"])
    training_set["bedrooms_per_room"] = (
        training_set["total_bedrooms"] / training_set["total_rooms"])
    training_set["population_per_household"] = (
        training_set["population"] / training_set["households"])
    corr_matrix = training_set.corr()
    print(corr_matrix["median_house_value"].sort_values(ascending=False))

if __name__ == '__main__':
    main()
