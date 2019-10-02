#!/usr/bin/env python

import numpy as np
import tensorflow as tf

n_classes = 10
width = 28
height = 28

# Prepare data.
fashion_labels = ["Shirt/top", "Trousers", "Pullover", "Dress", "Coat",
                  "Sandal", "Shirt", "Sneaker", "Bag", "Ankle boot"]
(x_train, y_train), (x_test, y_test) = tf.keras.datasets.fashion_mnist.load_data()
x_train = tf.cast(x_train / 255.0, tf.float32).numpy().reshape((60000, width * height))
x_test = tf.cast(x_test / 255.0, tf.float32).numpy().reshape((10000, width * height))

# split training sets into training and validation sets
split = 50000
x_train, x_valid = x_train[:split], x_train[split:]
y_train, y_valid = y_train[:split], y_train[split:]

y_train_ohe = tf.one_hot(y_train, depth=n_classes).numpy()
y_valid_ohe = tf.one_hot(y_valid, depth=n_classes).numpy()
y_test_ohe = tf.one_hot(y_test, depth=n_classes).numpy()

# Prepare model.
class LogisticRegression(tf.keras.Model):
  def __init__(self, num_classes):
    super(LogisticRegression, self).__init__()
    self.dense = tf.keras.layers.Dense(num_classes)

  def call(self, inputs, training=None, mask=None):
    output = self.dense(inputs)
    with tf.device('/cpu:0'):
      output = tf.nn.softmax(output)
    return output

model = LogisticRegression(n_classes)
optimiser = tf.keras.optimizers.Adam()
model.compile(optimizer=optimiser, loss='categorical_crossentropy', metrics=['accuracy'])

# Train.
batch_size = 128
epochs = 20
learning_rate = 0.1
# TF Keras tries to use the entire dataset to determine the shape without this
# step when using .fit(). So, use one sample of the provided input dataset size
# to determine input/output shapes for the model.
dummy_x = tf.zeros((1, width * height))
model.call(dummy_x)
checkpointer = tf.keras.callbacks.ModelCheckpoint(filepath="./model.weights.best.hdf5", verbose=2,
                                                  save_best_only=True, save_weights_only=True)
model.fit(x_train, y_train_ohe, batch_size=batch_size, epochs=epochs,
          validation_data=(x_valid, y_valid_ohe), callbacks=[checkpointer], verbose=2)
# load model with the best validation accuracy
model.load_weights("./model.weights.best.hdf5")

# Evaluate.
scores = model.evaluate(x_test, y_test_ohe, batch_size, verbose=2)
print("Final test loss and accuracy: ", scores)
y_predictions = model.predict(x_test)
