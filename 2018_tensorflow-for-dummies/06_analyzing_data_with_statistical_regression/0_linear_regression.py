#!/usr/bin/env python3

import tensorflow as tf


# Random input values
N = 40
x = tf.random_normal([N])
m_real = tf.truncated_normal([N], mean=2.0)
b_real = tf.truncated_normal([N], mean=3.0)
y = m_real * x + b_real

# Variables
m = tf.Variable(tf.random_normal([]))
b = tf.Variable(tf.random_normal([]))

# Compute model and loss
model = tf.add(tf.multiply(x, m), b)
loss = tf.reduce_mean(tf.pow(model - y, 2))

# Create optimizer
learn_rate = 0.1
num_epochs = 200
num_batches = N
optimizer = tf.train.GradientDescentOptimizer(learn_rate).minimize(loss)

# Initialize variables
init = tf.global_variables_initializer()

# Launch session
with tf.Session() as sess:
    sess.run(init)
    # Perform training
    for epoch in range(num_epochs):
        for batch in range(num_batches):
            sess.run(optimizer)

    # Display results
    print('m = ', sess.run(m))
    print('b = ', sess.run(b))
