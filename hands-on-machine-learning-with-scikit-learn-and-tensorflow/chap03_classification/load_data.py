#!/usr/bin/env python3
"""Load data."""

import random

from sklearn.datasets import fetch_mldata
import matplotlib
import matplotlib.pyplot as plt
import numpy as np

mnist = fetch_mldata('MNIST original')

data_rows = 70000
image_width = 28
assert (mnist.data.shape == (data_rows, image_width * image_width))


def show_image(idx = random.randint(0, data_rows)):
    """Show a random image from mnist."""
    image_data = mnist['data'][idx].reshape(image_width, image_width)
    plt.imshow(image_data, cmap = matplotlib.cm.binary, interpolation="nearest")
    plt.show()


def split_data():
    """Split the data to training and testing sets, and shuffle them."""
    train_size = 60000
    data, label = mnist['data'], mnist['target']
    shuffle_index = np.random.permutation(train_size)

    train_data = data[:train_size][shuffle_index]
    train_label = label[:train_size][shuffle_index]
    test_data = data[train_size:]
    test_label = label[train_size:]
    return train_data, train_label, test_data, test_label

if __name__ == '__main__':
    show_image()
