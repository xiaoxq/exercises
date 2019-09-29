#!/usr/bin/env python3

import tensorflow as tf


# Generator function
def generator():
    x = 20
    while x < 28:
        yield x
        x += 1


# Create an example containing floats
int_list = tf.train.Int64List(value=[0, 1, 2, 3])
feat = tf.train.Feature(int64_list=int_list)
container = tf.train.Features(feature={'feat': feat})
example = tf.train.Example(features=container)

# Write the example to a GZIP file
opts = tf.python_io.TFRecordOptions(tf.python_io.TFRecordCompressionType.GZIP)
with tf.python_io.TFRecordWriter('ex.tfrecord', opts) as writer:
    writer.write(example.SerializeToString())


# Function to parse TFRecords
def parse_func(buff):
    features = {'feat': tf.FixedLenFeature(shape=[4], dtype=tf.int64)}
    tensor_dict = tf.parse_single_example(buff, features)
    return tensor_dict['feat']


# Create a dataset from TFRecords
dset1 = tf.data.TFRecordDataset('ex.tfrecord', 'GZIP')
dset1 = dset1.map(parse_func)
iter1 = dset1.make_one_shot_iterator()
next1 = iter1.get_next()

# Create a parameterized dataset and reinitializable iterator
holder = tf.placeholder(tf.int64, shape=[2])
dset2 = tf.data.Dataset.from_tensor_slices(holder)
dset2 = dset2.concatenate(tf.data.Dataset.range(12, 14))

# Create the third dataset
dset3 = tf.data.Dataset.from_generator(generator, output_types=tf.int64)
dset3 = dset3.filter(lambda x: x < 24)

# Create a reinitializable iterator for the 2nd, 3rd datasets
iter2 = tf.data.Iterator.from_structure(dset2.output_types, dset2.output_shapes)
next2 = iter2.get_next()

# Create initializers for the 2nd, 3rd datasets
dset2_init = iter2.make_initializer(dset2)
dset3_init = iter2.make_initializer(dset3)

# Print the content of each dataset
with tf.Session() as sess:
    # Print the content of the first dataset
    print('Element from dset1: ', sess.run(next1))
    # Print the content of the second dataset
    sess.run(dset2_init, feed_dict={holder: [10, 11]})
    for _ in range(4):
        print('Element from dset2: ', sess.run(next2))

    # Print the content of the third dataset
    sess.run(dset3_init)
    for _ in range(4):
        print('Element from dset3: ', sess.run(next2))
