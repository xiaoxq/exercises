#!/usr/bin/env python3
"""Multi output classification."""

from sklearn.neighbors import KNeighborsClassifier
import matplotlib
import matplotlib.pyplot as plt
import numpy as np

import load_data


if __name__ == '__main__':
    train_data, _, test_data, _ = load_data.split_data()

    train_mod = train_data + np.random.randint(0, 100, (len(train_data), 784))
    test_mod = test_data + np.random.randint(0, 100, (len(test_data), 784))

    knn_clf = KNeighborsClassifier()
    knn_clf.fit(train_mod, train_data)

    random_index = 100
    clean_digit = knn_clf.predict([test_mod[random_index]])

    plt.subplot(121)
    src_image = test_mod[random_index].reshape(28, 28)
    plt.imshow(src_image, cmap=matplotlib.cm.binary, interpolation="nearest")

    plt.subplot(122)
    clean_image = clean_digit.reshape(28, 28)
    plt.imshow(clean_image, cmap=matplotlib.cm.binary, interpolation="nearest")

    plt.show()
