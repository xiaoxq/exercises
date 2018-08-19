#!/usr/bin/env python3
import string
import time

import numpy as np
import tensorflow as tf

# Split text into words
words = None
with open('../data/lovecraft.txt', 'r') as f:
    kTrans = ''.maketrans('', '', string.punctuation)
    words = f.read().lower().translate(kTrans).split()
word_size = len(words)

# Convert words to values
word_set = set(words)
vocab_size = len(word_set)
word_id = {word: idx for idx, word in enumerate(word_set)}
print('Read {} words from {} vocabularies.'.format(word_size, vocab_size))

input_vals = np.asarray([word_id.get(word) for word in words])

# Set values
input_size = 6
batch_size = 10
num_hidden = 600

# Placeholders
input_holder = tf.placeholder(tf.float32, [batch_size, input_size])
label_holder = tf.placeholder(tf.float32, [batch_size, vocab_size])

# Reshape input and feed to RNN
cell = tf.contrib.rnn.BasicRNNCell(num_hidden)
outputs, _ = tf.contrib.rnn.static_rnn(cell, [input_holder], dtype=tf.float32)

# Compute loss
weights = tf.Variable(tf.random_normal([num_hidden, vocab_size]))
biases = tf.Variable(tf.random_normal([vocab_size]))
model = tf.matmul(outputs[-1], weights) + biases
loss = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(
    logits=model, labels=label_holder))

# Create optimizer and check result
optimizer = tf.train.AdagradOptimizer(0.1).minimize(loss)
check = tf.equal(tf.argmax(model, 1), tf.argmax(label_holder, 1))
correct = tf.reduce_sum(tf.cast(check, tf.float32))

# Execute the graph
start_time = time.time()
with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())
    input_block = np.empty([batch_size, input_size])
    label_block = np.empty([batch_size, vocab_size])

    step = 0
    num_correct = 0.
    accuracy = 0.
    kStatSize = 100
    while accuracy < 95.:
        for i in range(batch_size):
            offset = np.random.randint(word_size - (input_size + 1))
            end = offset + input_size
            input_block[i, :] = input_vals[offset:end]
            label_block[i, :] = np.eye(vocab_size)[input_vals[end]]
        _, corr = sess.run([optimizer, correct],
                           feed_dict={input_holder: input_block,
                                      label_holder: label_block})
        num_correct += corr
        accuracy = 100 * num_correct / (kStatSize * batch_size)
        if step % kStatSize == 0:
            print('Step', step, '- Accuracy =', accuracy)
            num_correct = 0
        step += 1

# Display timing result
duration = time.time() - start_time

print('Time to reach 95% accuracy: {:.2f} seconds'.format(duration))
