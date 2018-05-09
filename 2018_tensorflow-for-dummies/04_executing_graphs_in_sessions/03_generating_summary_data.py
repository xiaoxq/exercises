#!/usr/bin/env python3
import os

import tensorflow as tf

a = tf.constant(2.5)
b = tf.constant(4.5)
total = a + b

# Create operations that generate summary data
tf.summary.scalar("a", a)
tf.summary.scalar("b", b)
tf.summary.scalar("total", total)

# Merge the operations into a single operation
merged_op = tf.summary.merge_all()

with tf.Session() as sess:
    _, summary = sess.run([total, merged_op])

    event_dir = os.path.basename(__file__) + '.event_dir'
    with tf.summary.FileWriter(event_dir) as writer:
        writer.add_summary(summary)
        print('Now you can run `tensorboard --logdir={}.event_dir`'.format(
            __file__))
