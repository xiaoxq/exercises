#!/usr/bin/env python3

import os
import sys

import cv2
import keras
import matplotlib.pyplot as plt
import numpy as np


def GetData():
    """Return an image"""
    img_file = os.path.join(os.path.dirname(sys.argv[0]),
                            'steam-locomotive.jpg')
    img = cv2.resize(cv2.imread(img_file), (224, 224))
    return np.expand_dims(img, axis=0)


def BuildModel():
    """Return model"""
    model = keras.applications.vgg16.VGG16(weights='imagenet', include_top=True)
    sgd = keras.optimizers.SGD(lr=0.1, decay=1e-6, momentum=0.9, nesterov=True)
    model.compile(optimizer=sgd, loss='categorical_crossentropy')
    return model


def Predict(model, input):
    """Predict on data"""
    output = model.predict(input)
    plt.plot(output.ravel())
    plt.show()
    print(np.argmax(output))  # Should print 820 for steaming train


if __name__ == '__main__':
    np.random.seed(1671)  # For reproducibility.
    model = BuildModel()
    input = GetData()
    Predict(model, input)
