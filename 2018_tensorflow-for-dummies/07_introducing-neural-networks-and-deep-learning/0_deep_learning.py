#!/usr/bin/env python3

import tensorflow as tf
import tensorflow.contrib.learn as tflearn


# Read MNIST data
dataset = tflearn.datasets.mnist.read_data_sets('MNIST-data', one_hot=True)

# Placeholders for MNIST images
image_holder = tf.placeholder(tf.float32, [None, 784])
label_holder = tf.placeholder(tf.float32, [None, 10])

# Layer settings
hidden_nodes = 200
output_nodes = 10

# Define weights
w0 = tf.Variable(tf.random_normal([784, hidden_nodes]))
w1 = tf.Variable(tf.random_normal([hidden_nodes, hidden_nodes]))
w2 = tf.Variable(tf.random_normal([hidden_nodes, hidden_nodes]))
w3 = tf.Variable(tf.random_normal([hidden_nodes, output_nodes]))

# Define biases
b0 = tf.Variable(tf.random_normal([hidden_nodes]))
b1 = tf.Variable(tf.random_normal([hidden_nodes]))
b2 = tf.Variable(tf.random_normal([hidden_nodes]))
b3 = tf.Variable(tf.random_normal([output_nodes]))

# Create layers
layer_1 = tf.add(tf.matmul(image_holder, w0), b0)
layer_1 = tf.nn.relu(layer_1)
layer_2 = tf.add(tf.matmul(layer_1, w1), b1)
layer_2 = tf.nn.relu(layer_2)
layer_3 = tf.add(tf.matmul(layer_2, w2), b2)
layer_3 = tf.nn.relu(layer_3)
output_layer = tf.matmul(layer_3, w3) + b3

# Compute loss
loss = tf.reduce_mean(
    tf.nn.softmax_cross_entropy_with_logits(
        logits=output_layer, labels=label_holder))

# Create optimizer
learning_rate = 0.01
num_epochs = 15
batch_size = 100
num_batches = int(dataset.train.num_examples / batch_size)
optimizer = tf.train.AdamOptimizer(learning_rate).minimize(loss)

# Initialize variables
init = tf.global_variables_initializer()

# Launch session
with tf.Session() as sess:
    sess.run(init)
    for epoch in range(num_epochs):
        for batch in range(num_batches):
            image_batch, label_batch = dataset.train.next_batch(batch_size)
            sess.run([optimizer, loss], feed_dict={image_holder: image_batch,
                                                   label_holder: label_batch})

    # Determine success rate
    prediction = tf.equal(tf.argmax(output_layer, 1),
                          tf.argmax(label_holder, 1))
    success = tf.reduce_mean(tf.cast(prediction, tf.float32))
    print('Success rate: ',
          sess.run(success, feed_dict={image_holder: dataset.test.images,
                                       label_holder: dataset.test.labels}))
