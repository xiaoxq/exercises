#!/usr/bin/env python3

import tensorflow as tf

# Math with constant tensors
const_a = tf.constant(3.6)
const_b = tf.constant(1.2)
total = const_a + const_b

graph = tf.get_default_graph()
graph_def = graph.as_graph_def()
print(graph_def)

# tf.train.write(graph, os.getcwd(), 'graph.dat', as_text=True)
# tf.train.write(graph_def, os.getcwd(), 'graph.dat', as_text=True)
