#!/usr/bin/env python

import tensorflow as tf

# Prepare data.
mnist = tf.keras.datasets.mnist
(train_x, train_y), (test_x, test_y) = mnist.load_data()
train_x = tf.cast(train_x / 255.0, tf.float32)
test_x = tf.cast(test_x / 255.0, tf.float32)
train_y = tf.cast(train_y, tf.int64)
test_y = tf.cast(test_y, tf.int64)

# Prepare model.
model = tf.keras.models.Sequential([
  tf.keras.layers.Flatten(),
  tf.keras.layers.Dense(512, activation=tf.nn.relu),
  tf.keras.layers.Dropout(0.2),
  tf.keras.layers.Dense(10, activation=tf.nn.softmax)
])
# Or use "add" methord:
#   model = tf.keras.models.Sequential()
#   model.add(tf.keras.layers.Flatten())
#   model.add(tf.keras.layers.Dense(512, activation='relu'))
#   model.add(tf.keras.layers.Dropout(0.2))
#   model.add(tf.keras.layers.Dense(10, activation=tf.nn.softmax))
#
# Or use keras functional API:
#   inputs = tf.keras.Input(shape=(28, 28))
#   x = tf.keras.layers.Flatten()(inputs)
#   x = tf.keras.layers.Dense(512, activation='relu', name='d1')(x)
#   x = tf.keras.layers.Dropout(0.2)(x)
#   predictions = tf.keras.layers.Dense(10, activation=tf.nn.softmax, name='d2')(x)
#   model = tf.keras.Model(inputs=inputs, outputs=predictions)
#
# Or use subclass:
#   class MyModel(tf.keras.Model):
#     def __init__(self, num_classes=10):
#       super(MyModel, self).__init__()
#       inputs = tf.keras.Input(shape=(28, 28))
#       self.x0 = tf.keras.layers.Flatten()
#       self.x1 = tf.keras.layers.Dense(512, activation='relu', name='d1')
#       self.x2 = tf.keras.layers.Dropout(0.2)
#       self.predictions = tf.keras.layers.Dense(10, activation=tf.nn.softmax, name='d2')
#     def call(self, inputs):
#       x = self.x0(inputs)
#       x = self.x1(x)
#       x = self.x2(x) 
#       return self.predictions(x)
#   model = MyModel()

optimiser = tf.keras.optimizers.Adam()
model.compile(optimizer=optimiser, loss='sparse_categorical_crossentropy', metrics = ['accuracy'])

# Train.
epochs = 10
batch_size = 32  # 32 is default in fit method but specify anyway
model.fit(train_x, train_y, batch_size=batch_size, epochs=epochs)

# Evaluate.
model.evaluate(test_x, test_y)
model.summary()
