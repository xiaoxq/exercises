#!/usr/bin/env python

import matplotlib.pyplot as plt
import numpy as np
import tensorflow as tf


# Prepare data.
(x_train, _), (x_test, _) = tf.keras.datasets.fashion_mnist.load_data()
# Flatten
x_train = x_train.astype('float32') / 255.0
x_train = x_train.reshape((x_train.shape[0], np.prod(x_train.shape[1:])))
x_test = x_test.astype('float32') / 255.0
x_test = x_test.reshape((x_test.shape[0], np.prod(x_test.shape[1:])))

# Prepare model.
image_dim = 784  # Size of our input image, 784
encoding_dim = 32  # Length of our encoded items.Compression of factor=784/32=24.5
input_image = tf.keras.layers.Input(shape=(image_dim, ))
regularizer = tf.keras.regularizers.l1(10e-5)
encoded_image = tf.keras.layers.Dense(
    encoding_dim, activation='relu', activity_regularizer=regularizer)(input_image)
encoder = tf.keras.models.Model(input_image, encoded_image)

# "decoded" is the lossy reconstruction of the input
decoded_image = tf.keras.layers.Dense(image_dim, activation='sigmoid')(encoded_image)
# this model maps an input to its reconstruction
autoencoder = tf.keras.models.Model(input_image, decoded_image)
# create a placeholder for an encoded (32-dimensional) input
encoded_input = tf.keras.layers.Input(shape=(encoding_dim,))
# retrieve the last layer of the autoencoder model
decoder_layer = autoencoder.layers[-1]
# create the decoder model
decoder = tf.keras.models.Model(encoded_input, decoder_layer(encoded_input))
autoencoder.compile(optimizer='adadelta', loss='binary_crossentropy')

# Checkpointers
checkpointer1 = tf.keras.callbacks.ModelCheckpoint(
    filepath='model.weights.best.hdf5', verbose=2, save_best_only=True)
checkpointer2 = tf.keras.callbacks.EarlyStopping(
    monitor='val_loss', min_delta=0.0005, patience=2, verbose=2, mode='auto')

# Train
epochs = 500
autoencoder.fit(x_train, x_train, epochs=epochs, batch_size=256, verbose=2,
                callbacks=[checkpointer1],
                # callbacks=[checkpointer2],
                shuffle=True, validation_data=(x_test, x_test))

# Test
encoded_images = encoder.predict(x_test)  # compress
decoded_images = decoder.predict(encoded_images)  # decompress

# Display results
number_of_items = 12 # how many items we will display
plt.figure(figsize=(20, 4))
for i in range(number_of_items):
  # display items before compression 
  graph = plt.subplot(2, number_of_items, i + 1)
  plt.imshow(x_test[i].reshape(28, 28))
  plt.gray()
  graph.get_xaxis().set_visible(False)
  graph.get_yaxis().set_visible(False)

  # display items after decompression
  graph = plt.subplot(2, number_of_items, i + 1 + number_of_items)
  plt.imshow(decoded_images[i].reshape(28, 28))
  plt.gray()
  graph.get_xaxis().set_visible(False)
  graph.get_yaxis().set_visible(False)
plt.show()
