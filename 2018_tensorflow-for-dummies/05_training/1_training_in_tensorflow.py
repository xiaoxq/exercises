#!/usr/bin/env python3
import os

import tensorflow as tf


# Define a trainable variable
x_var = tf.Variable(0., name='x_result')
# Express loss in terms of the variable
loss = x_var * x_var - 4.0 * x_var + 5.0

# Define an untrainable variable to hold the global step
step_var = tf.Variable(0, trainable=False)
# Find variable value that minimizes loss
learn_rate = 0.1
optimizer = tf.train.GradientDescentOptimizer(learn_rate).minimize(
    loss, global_step=step_var)

# Create summary data and FileWriter
summary_op = tf.summary.scalar('x', x_var)
file_writer = tf.summary.FileWriter('summary', graph=tf.get_default_graph())

with tf.Session() as sess:
    # Initialize variables
    init = tf.global_variables_initializer()

    sess.run(init)
    num_epochs = 40
    for epoch in range(num_epochs):
        _, step, result, summary = sess.run([optimizer, step_var, x_var,
                                             summary_op])
        print('Step %d: Computed result = %f' % (step, result))

        # Print summary data
        file_writer.add_summary(summary, global_step=step)
        file_writer.flush()

    # Store variable data
    tf.train.Saver().save(sess, os.getcwd() + '/output')
    print('Final x_var: %f' % sess.run(x_var))

print('Now you can run `tensorboard --logdir=summary`')
