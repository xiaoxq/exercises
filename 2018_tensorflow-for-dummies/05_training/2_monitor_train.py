#!/usr/bin/env python3
import tensorflow as tf


# Custom session hook
class CustomHook(tf.train.SessionRunHook):
    def begin(self):
        print('Beginning the session!')

    def before_run(self, run_context):
        return tf.train.SessionRunArgs(loss)

    def after_run(self, run_context, run_values):
        if run_context.original_args != 'init':
            print('Loss: ', run_values.results)

    def end(self, session):
        print('The session is about to end!')


# Define a trainable variable
x_var = tf.Variable(0., name='x_result')

# Define an untrainable variable to hold the global step
step_var = tf.train.create_global_step()

# Express loss in terms of the variable
loss = x_var * x_var - 4.0 * x_var + 5.0

# Find variable value that minimizes loss
learn_rate = 0.1
num_epochs = 40
optimizer = tf.train.GradientDescentOptimizer(learn_rate).minimize(loss, global_step=step_var)

# Initialize variables
init = tf.global_variables_initializer()

# Create summary operation
summary_op = tf.summary.scalar('x', x_var)

# Create hooks
custom_hook = CustomHook()
checkpoint_hook = tf.train.CheckpointSaverHook(checkpoint_dir='ckpt_dir',
                                               checkpoint_basename='output', save_steps=10)
summary_hook = tf.train.SummarySaverHook(save_steps=10, output_dir='log', summary_op=summary_op)
hooks = [custom_hook, checkpoint_hook, summary_hook]

# Launch session
with tf.train.MonitoredSession(hooks=hooks) as sess:
    sess.run(init)
    for epoch in range(num_epochs):
        sess.run(optimizer)
