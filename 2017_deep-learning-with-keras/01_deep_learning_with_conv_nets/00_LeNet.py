#!/usr/bin/env python3

import keras
import numpy as np

NB_CLASSES = 10
VERBOSE = 1


def GetData():
    """Return X_train, Y_train, X_test, Y_test"""
    (X_train, y_train), (X_test, y_test) = keras.datasets.mnist.load_data()
    # X_train is 60000 rows of 28x28 values. Normalize it.
    X_train = (X_train.astype('float32') / 255)[:, :, :, np.newaxis]
    # X_test is 10000 rows of 28x28 values.
    X_test = (X_test.astype('float32') / 255)[:, :, :, np.newaxis]
    # Convert class vectors to binary class matrices
    Y_train = keras.utils.np_utils.to_categorical(y_train, NB_CLASSES)
    Y_test = keras.utils.np_utils.to_categorical(y_test, NB_CLASSES)
    return X_train, Y_train, X_test, Y_test


def BuildModel():
    """Return model"""
    INPUT_SHAPE = (28, 28, 1)
    N_HIDDEN = 500
    DROPOUT = 0.3

    model = keras.models.Sequential()
    model.add(keras.layers.convolutional.Convolution2D(
        20, kernel_size=5, padding="same", input_shape=INPUT_SHAPE))
    model.add(keras.layers.core.Activation('relu'))
    model.add(keras.layers.convolutional.MaxPooling2D(
        pool_size=(2, 2), strides=(2, 2)))

    model.add(keras.layers.convolutional.Conv2D(
        50, kernel_size=5, border_mode="same"))
    model.add(keras.layers.core.Activation("relu"))
    model.add(keras.layers.convolutional.MaxPooling2D(
        pool_size=(2, 2), strides=(2, 2)))

    model.add(keras.layers.core.Flatten())
    model.add(keras.layers.core.Dense(N_HIDDEN))
    model.add(keras.layers.core.Activation("relu"))

    model.add(keras.layers.core.Dense(NB_CLASSES))
    model.add(keras.layers.core.Activation('softmax'))

    model.compile(loss='categorical_crossentropy',
                  optimizer=keras.optimizers.Adam(),
                  metrics=['accuracy'])
    return model


def Train(model, X_train, Y_train):
    """Train on data"""
    EPOCHS = 20
    BATCH_SIZE = 128
    VALIDATION_SPLIT = 0.2  # How much TRAIN is reserved for VALIDATION

    model.fit(X_train, Y_train,
              batch_size=BATCH_SIZE, epochs=EPOCHS, verbose=VERBOSE,
              validation_split=VALIDATION_SPLIT)


def Evaluate(model, X_test, Y_test):
    """Evaluate on data"""
    score = model.evaluate(X_test, Y_test, verbose=VERBOSE)
    print("\n\nTest score:", score[0])
    print("Test accuracy:", score[1])


if __name__ == '__main__':
    np.random.seed(1671)  # For reproducibility.
    model = BuildModel()
    X_train, Y_train, X_test, Y_test = GetData()
    Train(model, X_train, Y_train)
    Evaluate(model, X_test, Y_test)
