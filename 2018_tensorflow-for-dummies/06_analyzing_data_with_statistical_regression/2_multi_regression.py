#!/usr/bin/env python3

import tensorflow as tf
import tensorflow.contrib.learn as learn


# Read MNIST data
dataset = learn.datasets.mnist.read_data_sets('MNIST-data', one_hot=True)

# Placeholders for MNIST images
image_holder = tf.placeholder(tf.float32, [None, 784])
label_holder = tf.placeholder(tf.float32, [None, 10])

# Variables
m = tf.Variable(tf.zeros([784, 10]))
b = tf.Variable(tf.zeros([10]))

# Compute loss
loss = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(
    logits=tf.matmul(image_holder, m) + b, labels=label_holder))

# Create optimizer
learning_rate = 0.01
num_epochs = 25
batch_size = 100
num_batches = int(dataset.train.num_examples/batch_size)
optimizer = tf.train.GradientDescentOptimizer(learning_rate).minimize(loss)

# Initialize variables
init = tf.global_variables_initializer()

# Launch session
with tf.Session() as sess:
    sess.run(init)
    for epoch in range(num_epochs):
        for batch in range(num_batches):
            image_batch, label_batch = dataset.train.next_batch(batch_size)
            _, lossVal = sess.run([optimizer, loss],feed_dict={
                image_holder: image_batch, label_holder: label_batch})

    # Display the final loss
    print('Final loss: ', lossVal)
