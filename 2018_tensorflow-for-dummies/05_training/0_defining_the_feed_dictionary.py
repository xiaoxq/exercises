#!/usr/bin/env python3

import numpy as np
import tensorflow as tf

ph = tf.placeholder(tf.float32)
vals = np.array([9., 8., 7.])
incr = tf.add(ph, 1.)
with tf.Session() as sess:
    res = sess.run(incr, feed_dict={ph: vals})
    print(res)
