#!/usr/bin/env python

import os

import matplotlib.pyplot as plt
import numpy as np


def perceptronStep(X, y, W, b, learn_rate=0.01):
    # Update W and b.
    for i in range(len(y)):
        y_hat = 1 if np.matmul(X[i], W) + b >= 0 else 0
        y_diff = y[i] - y_hat
        if y_diff == 1:
            W[0] += X[i][0] * learn_rate
            W[1] += X[i][1] * learn_rate
            b += learn_rate
        elif y_diff == -1:
            W[0] -= X[i][0] * learn_rate
            W[1] -= X[i][1] * learn_rate
            b -= learn_rate
    return W, b


def trainPerceptronAlgorithm(X, y, learn_rate=0.01, num_epochs=1000):
    W = np.random.rand(2, 1)
    b = np.random.rand()
    for _ in range(num_epochs):
        W, b = perceptronStep(X, y, W, b, learn_rate)
    return W, b


def drawResult(X, y, W, b):
    X0 = X[y == 0]
    X1 = X[y == 1]
    plt.scatter(X0[:, 0], X0[:, 1])
    plt.scatter(X1[:, 0], X1[:, 1])

    min_x = min(X.T[0])
    max_x = max(X.T[0])

    def getX2(x1): return - (W[0] * x1 + b) / W[1]
    plt.plot([min_x, max_x], [getX2(min_x), getX2(max_x)])

    plt.show()


def getInput():
    data_file = os.path.join(os.path.dirname(__file__), 'data.csv')
    rows = np.genfromtxt(data_file, delimiter=',')
    return rows[:, [0, 1]], rows[:, 2]


if __name__ == '__main__':
    X, y = getInput()
    W, b = trainPerceptronAlgorithm(X, y)
    drawResult(X, y, W, b)
