#!/usr/bin/env python
"""Show data hist."""

import matplotlib.pyplot as plt

import load_data


def main():
    """Main function."""
    housing_data = load_data.load_housing_data()
    housing_data.hist(bins=50, figsize=(20, 15))
    plt.show()

if __name__ == '__main__':
    main()
