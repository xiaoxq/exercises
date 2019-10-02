#!/usr/bin/env python

import numpy as np
import tensorflow as tf


training_steps = 1000  # number of steps we are going to train for
display_step = 100  # after multiples of this, we display the loss
learning_rate = 0.01  # multiplying factor on gradients

# Prepare data: y = m * x + c
m, c = 6, -5  # gradient and y-intercept of our line, edit these for a different linear problem
n_examples = 1000  # number of training examples


def train_data(n, m, c):
  x = tf.random.normal([n])  # n values taken from a normal distribution,
  noise = tf.random.normal([n])  # n values taken from a normal distribution
  y = m*x + c + noise  # our scatter plot
  return x, y


def prediction(x, weight, bias):
  return weight*x + bias  # our predicted (learned) m and c, expression is like y = m*x + c


def loss(x, y, weights, biases): 
  error = prediction(x, weights, biases) - y  # how 'wrong' our predicted (learned) y is
  squared_error = tf.square(error)
  return tf.reduce_mean(input_tensor=squared_error)  # overall mean of squared error, scalar value.


def grad(x, y, weights, biases):
  with tf.GradientTape() as tape:
    loss_ = loss(x, y, weights, biases)
  # direction and value of the gradient of our weights and biases
  return tape.gradient(loss_, [weights, biases])


x, y = train_data(n_examples,m,c)  # our training values x and y
W = tf.Variable(np.random.randn())  # initial, random, value for predicted weight (m)
B = tf.Variable(np.random.randn())  # initial, random, value for predicted bias (c)
for step in range(training_steps):  # iterate for each training step
  deltaW, deltaB = grad(x, y, W, B)  # direction(sign) and value of the gradients of our loss 
  # with respect to our weights and bias
  change_W = deltaW * learning_rate  # adjustment amount for weight
  change_B = deltaB * learning_rate  # adjustment amount for bias
  W.assign_sub(change_W)  # subract change_W from W
  B.assign_sub(change_B)  # subract change_B from B
  print("Loss at step {:02d}: {:.6f}".format(step, loss(x, y, W, B)))

print("Final loss: {:.3f}".format(loss(x, y, W, B)))
print("W = {}, B = {}".format(W.numpy(), B.numpy()))
