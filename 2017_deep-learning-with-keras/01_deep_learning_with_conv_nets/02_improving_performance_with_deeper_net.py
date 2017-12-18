#!/usr/bin/env python3

import keras
import numpy as np

NB_CLASSES = 10
VERBOSE = 1


def GetData():
    """Return X_train, Y_train, X_test, Y_test"""
    (X_train, y_train), (X_test, y_test) = keras.datasets.cifar10.load_data()
    # Data point is 32x32 images with 3 channels. Normalize it.
    X_train = X_train.astype('float32') / 255
    X_test = X_test.astype('float32') / 255
    # Convert class vectors to binary class matrices
    Y_train = keras.utils.np_utils.to_categorical(y_train, NB_CLASSES)
    Y_test = keras.utils.np_utils.to_categorical(y_test, NB_CLASSES)
    return X_train, Y_train, X_test, Y_test


def BuildModel():
    """Return model"""
    N_HIDDEN = 512
    CONV_KERNEL = (3, 3)
    INPUT_SHAPE = (32, 32, 3)
    POOL_DROPOUT = 0.25
    HIDDEN_DROPOUT = 0.5

    model = keras.models.Sequential()
    model.add(keras.layers.convolutional.Conv2D(
        32, CONV_KERNEL, padding="same", input_shape=INPUT_SHAPE))
    model.add(keras.layers.core.Activation('relu'))

    model.add(keras.layers.convolutional.Conv2D(32, (3, 3), padding='same'))
    model.add(keras.layers.core.Activation('relu'))

    model.add(keras.layers.convolutional.MaxPooling2D(pool_size=(2, 2)))
    model.add(keras.layers.core.Dropout(POOL_DROPOUT))

    model.add(keras.layers.convolutional.Conv2D(64, (3, 3), padding='same'))
    model.add(keras.layers.core.Activation('relu'))

    model.add(keras.layers.convolutional.Conv2D(64, (3, 3)))
    model.add(keras.layers.core.Activation('relu'))

    model.add(keras.layers.convolutional.MaxPooling2D(pool_size=(2, 2)))
    model.add(keras.layers.core.Dropout(POOL_DROPOUT))

    model.add(keras.layers.core.Flatten())
    model.add(keras.layers.core.Dense(N_HIDDEN))
    model.add(keras.layers.core.Activation("relu"))
    model.add(keras.layers.core.Dropout(HIDDEN_DROPOUT))

    model.add(keras.layers.core.Dense(NB_CLASSES))
    model.add(keras.layers.core.Activation('softmax'))

    model.compile(loss='categorical_crossentropy',
                  optimizer=keras.optimizers.RMSprop(),
                  metrics=['accuracy'])
    return model


def Train(model, X_train, Y_train):
    """Train on data"""
    EPOCHS = 40
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
