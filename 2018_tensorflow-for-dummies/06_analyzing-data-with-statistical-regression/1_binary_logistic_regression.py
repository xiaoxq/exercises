#!/usr/bin/env python3

import tensorflow as tf


# Input values
N = 40
x = tf.lin_space(0., 5., N)
y = tf.constant([0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
                 1., 0., 0., 1., 0., 0., 0., 1., 0., 0.,
                 1., 0., 1., 1., 1., 1., 1., 1., 1., 1.,
                 1., 1., 1., 1., 1., 1., 1., 1., 1., 1.])

# Variables
m = tf.Variable(0.)
b = tf.Variable(0.)

# Compute model and loss
model = tf.nn.sigmoid(tf.add(tf.multiply(x, m), b))
loss = -1. * tf.reduce_sum(y * tf.log(model) + (1. - y) * (1. - tf.log(model)))

# Create optimizer
learn_rate = 0.005
num_epochs = 350
optimizer = tf.train.GradientDescentOptimizer(learn_rate).minimize(loss)

# Initialize variables
init = tf.global_variables_initializer()

# Launch session
with tf.Session() as sess:
    sess.run(init)
    # Run optimizer
    for epoch in range(num_epochs):
        sess.run(optimizer)

    # Display results
    print('m =', sess.run(m))
    print('b =', sess.run(b))
