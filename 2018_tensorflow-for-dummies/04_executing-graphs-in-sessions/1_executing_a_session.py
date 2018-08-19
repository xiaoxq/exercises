#!/usr/bin/env python3

import tensorflow as tf

t1 = tf.constant(7)
t2 = tf.constant(2)
with tf.Session() as sess:
    res = sess.run(t1 + t2)
    print(res)

# In interactive mode, use InteractiveSession to avoid block closing.
#   sess = tf.InteractiveSession()
#   res = sess.run(t1 + t2)
