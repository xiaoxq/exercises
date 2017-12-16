#!/usr/bin/env python3

import keras
import numpy as np

# Load data
np.random.seed(1671)  # For reproducibility.
(X_train, y_train), (X_test, y_test) = keras.datasets.mnist.load_data()
RESHAPED = 784
# X_train is 60000 rows of 28x28 values. Reshape and normalize.
X_train = X_train.reshape(60000, RESHAPED).astype('float32') / 255
# X_test is 10000 rows of 28x28 values.
X_test = X_test.reshape(10000, RESHAPED).astype('float32') / 255
# Convert class vectors to binary class matrices
NB_CLASSES=10
Y_train = keras.utils.np_utils.to_categorical(y_train, NB_CLASSES)
Y_test = keras.utils.np_utils.to_categorical(y_test, NB_CLASSES)


EPOCHS=200
BATCH_SIZE=128
# How much TRAIN is reserved for VALIDATION
VALIDATION_SPLIT=0.2
VERBOSE=1


model = keras.models.Sequential()
model.add(keras.layers.core.Dense(NB_CLASSES, input_shape=(RESHAPED,)))
model.add(keras.layers.core.Activation('softmax'))
model.compile(loss='categorical_crossentropy',
              optimizer=keras.optimizers.SGD(),
              metrics=['accuracy'])
model.fit(X_train, Y_train,
          batch_size=BATCH_SIZE, epochs=EPOCHS, verbose=VERBOSE,
          validation_split=VALIDATION_SPLIT)

score = model.evaluate(X_test, Y_test, verbose=VERBOSE)
print("Test score:", score[0])
print("Test accuracy:", score[1])
