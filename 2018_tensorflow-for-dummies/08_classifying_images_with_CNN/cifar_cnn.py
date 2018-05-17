#!/usr/bin/env python3
import glob
import pickle
import random

import numpy as np
import tensorflow as tf


# Set parameters
image_size = 32
num_channels = 3
num_categories = 10
num_filters = 32
filter_size = 5
num_epochs = 200
batch_size = 10
num_batches = int(50000 / batch_size)
keep_prob = 0.6

train_files = glob.glob('../data/cifar-10-batches-py/data_batch_?')
test_file = '../data/cifar-10-batches-py/test_batch'

# Read CIFAR training data
train_data = None
train_labels = None
for file_name in train_files:
    train_dict = None
    with open(file_name, 'rb') as fin:
        train_dict = pickle.load(fin, encoding='latin1')
    if train_data is None:
        train_data = np.array(train_dict['data'], float) / 255.0
        train_labels = train_dict['labels']
    else:
        train_data = np.concatenate((train_data, train_dict['data']), 0)
        train_labels = np.concatenate((train_labels, train_dict['labels']), 0)

# Preprocess training data and labels
train_data = train_data \
    .reshape([-1, num_channels, image_size, image_size]) \
    .transpose([0, 2, 3, 1])
train_labels = np.eye(num_categories)[train_labels]

# Read CIFAR test data
test_dict = None
with open(test_file, 'rb') as fin:
    test_dict = pickle.load(fin, encoding='latin1')
test_data = test_dict['data'] \
    .reshape([-1, num_channels, image_size, image_size]) \
    .transpose([0, 2, 3, 1])
test_labels = np.eye(num_categories)[test_dict['labels']]

# Placeholders for CIFAR images
img_holder = tf.placeholder(tf.float32,
                            [None, image_size, image_size, num_channels])
lbl_holder = tf.placeholder(tf.float32, [None, num_categories])
train = tf.placeholder(tf.bool)

# Create convolution/pooling layers
conv1 = tf.layers.conv2d(img_holder, num_filters, filter_size, padding='same',
                         activation=tf.nn.relu)
drop1 = tf.layers.dropout(conv1, keep_prob, training=train)
pool1 = tf.layers.max_pooling2d(drop1, 2, 2)

conv2 = tf.layers.conv2d(pool1, num_filters, filter_size, padding='same',
                         activation=tf.nn.relu)
drop2 = tf.layers.dropout(conv2, keep_prob, training=train)
pool2 = tf.layers.max_pooling2d(drop2, 2, 2)

conv3 = tf.layers.conv2d(pool2, num_filters, filter_size, padding='same',
                         activation=tf.nn.relu)
pool3 = tf.layers.max_pooling2d(conv3, 2, 2)

conv4 = tf.layers.conv2d(pool3, num_filters, filter_size, padding='same',
                         activation=tf.nn.relu)
drop3 = tf.layers.dropout(conv4, keep_prob, training=train)

# Flatten input data
flatten = tf.reshape(drop3, [-1, 512])

# Create connected layers
with tf.contrib.framework.arg_scope([tf.contrib.layers.fully_connected],
                                    normalizer_fn=tf.contrib.layers.batch_norm,
                                    normalizer_params={'is_training': train}):
    fc1 = tf.contrib.layers.fully_connected(flatten, 512)
    fc2 = tf.contrib.layers.fully_connected(fc1, num_categories,
                                            activation_fn=None)

# Compute loss
loss = tf.reduce_mean(
    tf.nn.softmax_cross_entropy_with_logits(logits=fc2, labels=lbl_holder))

# Create optimizer
learning_rate = 0.0005
optimizer = tf.train.AdamOptimizer(learning_rate).minimize(loss)

# Initialize variables
init = tf.global_variables_initializer()

# Launch session
with tf.Session() as sess:
    sess.run(init)
    for epoch in range(num_epochs):
        for batch in range(num_batches):
            batch_start = random.randint(0, batch_size*(num_batches-1)-1)
            batch_end = batch_start + batch_size
            img_batch = train_data[batch_start:batch_end, :]
            lbl_batch = train_labels[batch_start:batch_end, :]
            sess.run(optimizer, feed_dict={img_holder: img_batch,
                                           lbl_holder: lbl_batch,
                                           train: True})

    prediction = tf.equal(tf.argmax(fc2, 1), tf.argmax(lbl_holder, 1))
    accuracy = tf.reduce_mean(tf.cast(prediction, tf.float32))
    print('Accuracy: ', sess.run(accuracy, feed_dict={img_holder: test_data,
                                                      lbl_holder: test_labels,
                                                      train: False}))
