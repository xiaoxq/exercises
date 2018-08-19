#!/usr/bin/env python3

import tensorflow as tf
import tensorflow.contrib.learn as tflearn
from tensorflow.contrib.layers import fully_connected

# Read MNIST data
dataset = tflearn.datasets.mnist.read_data_sets('MNIST-data', one_hot=True)

# Placeholders for MNIST images
image_holder = tf.placeholder(tf.float32, [None, 784])
label_holder = tf.placeholder(tf.float32, [None, 10])
train = tf.placeholder(tf.bool)

# Layer settings
hidden_nodes = 200
output_nodes = 10
keep_prob = 0.5

# Create layers
with tf.contrib.framework.arg_scope([fully_connected],
                                    normalizer_fn=tf.contrib.layers.batch_norm,
                                    normalizer_params={'is_training': train}):
    layer1 = fully_connected(image_holder, hidden_nodes, scope='layer1')
    layer1_drop = tf.layers.dropout(layer1, keep_prob, training=train)

    layer2 = fully_connected(layer1_drop, hidden_nodes, scope='layer2')
    layer2_drop = tf.layers.dropout(layer2, keep_prob, training=train)

    layer3 = fully_connected(layer2_drop, hidden_nodes, scope='layer3')
    layer3_drop = tf.layers.dropout(layer3, keep_prob, training=train)

    output_layer = fully_connected(layer3_drop, output_nodes,
                                   activation_fn=None, scope='layer4')

# Compute loss
loss = tf.reduce_mean(
    tf.nn.softmax_cross_entropy_with_logits(
        logits=output_layer, labels=label_holder))

# Create optimizer
learning_rate = 0.01
num_epochs = 15
batch_size = 100
num_batches = int(dataset.train.num_examples/batch_size)
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
                                                   label_holder: label_batch,
                                                   train: True})

    # Determine success rate
    prediction = tf.equal(tf.argmax(output_layer, 1),
                          tf.argmax(label_holder, 1))
    success = tf.reduce_mean(tf.cast(prediction, tf.float32))
    print('Success rate: ',
          sess.run(success, feed_dict={image_holder: dataset.test.images,
                                       label_holder: dataset.test.labels,
                                       train: False}))
