#!/usr/bin/env python3

import keras
import numpy as np

RESHAPED = 784
NB_CLASSES = 10
VERBOSE = 1


def GetData():
    """Return X_train, Y_train, X_test, Y_test"""
    (X_train, y_train), (X_test, y_test) = keras.datasets.mnist.load_data()
    # X_train is 60000 rows of 28x28 values. Reshape and normalize.
    X_train = X_train.reshape(60000, RESHAPED).astype('float32') / 255
    # X_test is 10000 rows of 28x28 values.
    X_test = X_test.reshape(10000, RESHAPED).astype('float32') / 255
    # Convert class vectors to binary class matrices
    Y_train = keras.utils.np_utils.to_categorical(y_train, NB_CLASSES)
    Y_test = keras.utils.np_utils.to_categorical(y_test, NB_CLASSES)
    return X_train, Y_train, X_test, Y_test


def BuildModel():
    """Return model"""
    N_HIDDEN = 128
    DROPOUT = 0.3

    model = keras.models.Sequential()
    model.add(keras.layers.core.Dense(N_HIDDEN, input_shape=(RESHAPED,)))
    model.add(keras.layers.core.Activation('relu'))
    model.add(keras.layers.core.Dropout(DROPOUT))

    model.add(keras.layers.core.Dense(N_HIDDEN))
    model.add(keras.layers.core.Activation('relu'))
    model.add(keras.layers.core.Dropout(DROPOUT))

    model.add(keras.layers.core.Dense(NB_CLASSES))
    model.add(keras.layers.core.Activation('softmax'))

    model.compile(loss='categorical_crossentropy',
                  optimizer=keras.optimizers.SGD(),
                  metrics=['accuracy'])
    return model


def Train(model, X_train, Y_train):
    """Train on data"""
    EPOCHS = 250
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
