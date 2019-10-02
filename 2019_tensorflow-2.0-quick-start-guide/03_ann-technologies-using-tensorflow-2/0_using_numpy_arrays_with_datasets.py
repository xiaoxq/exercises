#!/usr/bin/env python

import numpy as np
import tensorflow as tf


np_array1 = np.arange(10)
np_array2 = np.arange(10, 20)


def print_iterator(iter):
  while True:
    try:
      num = iter.get_next()
      if isinstance(num, tuple):
        print([element.numpy() for element in num])
      else:
        print(num.numpy())
    except tf.errors.OutOfRangeError:
      break


print('Numpy to dataset and iterator')
dataset = tf.data.Dataset.from_tensor_slices(np_array1)
iterator = tf.compat.v1.data.make_one_shot_iterator(dataset)
print_iterator(iterator)

print('Batch mode')
dataset = tf.data.Dataset.from_tensor_slices(np_array1).batch(3, drop_remainder=False)
iterator = tf.compat.v1.data.make_one_shot_iterator(dataset)
print_iterator(iterator)

print('Zip')
dataset1 = tf.data.Dataset.from_tensor_slices(np_array1)
dataset2 = tf.data.Dataset.from_tensor_slices(np_array2)
dataset = tf.data.Dataset.zip((dataset1, dataset2))
iterator = tf.compat.v1.data.make_one_shot_iterator(dataset)
print_iterator(iterator)

print('Concatenate')
dataset = dataset1.concatenate(dataset2)
iterator = tf.compat.v1.data.make_one_shot_iterator(dataset)
print_iterator(iterator)
