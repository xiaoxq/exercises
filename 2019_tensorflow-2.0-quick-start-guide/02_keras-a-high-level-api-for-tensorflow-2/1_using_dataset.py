#!/usr/bin/env python

import tensorflow as tf

# Prepare data.
mnist = tf.keras.datasets.mnist
(train_x, train_y), (test_x, test_y) = mnist.load_data()
train_x = tf.cast(train_x / 255.0, tf.float32)
test_x = tf.cast(test_x / 255.0, tf.float32)
train_y = tf.cast(train_y, tf.int64)
test_y = tf.cast(test_y, tf.int64)

batch_size = 32
buffer_size = 10000
train_dataset = (tf.data.Dataset.from_tensor_slices((train_x, train_y))
    .batch(batch_size)
    .shuffle(buffer_size)
    .map(lambda x, y: (tf.image.random_flip_left_right(x), y))
    .repeat())
test_dataset = (tf.data.Dataset.from_tensor_slices((test_x, test_y))
    .batch(batch_size)
    .shuffle(buffer_size))

# Prepare model.
model = tf.keras.models.Sequential([
  tf.keras.layers.Flatten(),
  tf.keras.layers.Dense(512, activation=tf.nn.relu),
  tf.keras.layers.Dropout(0.2),
  tf.keras.layers.Dense(10, activation=tf.nn.softmax)
])
optimiser = tf.keras.optimizers.Adam()
model.compile(optimizer=optimiser, loss='sparse_categorical_crossentropy', metrics=['accuracy'])

# Train.
epochs = 10
steps_per_epoch = len(train_x) // batch_size  # required because of the repeat on the dataset
model.fit(train_dataset, epochs=epochs, steps_per_epoch=steps_per_epoch)

# Evaluate.
model.evaluate(test_dataset)
model.summary()
