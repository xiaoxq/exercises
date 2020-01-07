#!/usr/bin/env python

import multiprocessing


def function_square(data):
    return data * data


if __name__ == '__main__':
    inputs = list(range(0, 100))
    pool = multiprocessing.Pool(processes=4)
    pool_outputs = pool.map(function_square, inputs)
    pool.close()
    pool.join()
    print(pool_outputs)
