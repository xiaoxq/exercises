#!/usr/bin/env python3
"""Show training_set geo scatter plot."""

import matplotlib.pyplot as plt

import load_data


def main():
    """Main function."""
    training_set, _ = load_data.split_train_and_test_set()
    training_set.plot(kind="scatter", x="longitude", y="latitude", alpha=0.4,
                      s=training_set["population"]/100, label="population",
                      c="median_house_value", cmap=plt.get_cmap("jet"),
                      colorbar=True)
    plt.show()

if __name__ == '__main__':
    main()
