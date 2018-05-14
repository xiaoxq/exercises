#!/usr/bin/env python3

import tensorflow as tf

tf.logging.set_verbosity(tf.logging.INFO)
with tf.Session() as sess:
    tf.logging.debug('DEBUG')
    tf.logging.info('INFO')
    tf.logging.warn('WARN')
    tf.logging.error('ERROR')
    tf.logging.fatal('FATAL')

    tf.logging.log(tf.logging.INFO, 'INFO 2')
    tf.logging.log_if(tf.logging.INFO, 'INFO Never Show', False)

    for i in range(5):
        tf.logging.log_first_n(tf.logging.INFO, 'log_first_3 %d', 3, i)
    for i in range(5):
        tf.logging.log_every_n(tf.logging.INFO, 'log_every_3 %d', 3, i)
