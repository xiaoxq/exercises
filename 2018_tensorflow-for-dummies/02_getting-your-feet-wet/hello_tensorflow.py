#!/usr/bin/env python3

import tensorflow as tf

msg = tf.string_join(["Hello ", "TensorFlow!"])
with tf.Session() as sess:
    print(sess.run(msg))
