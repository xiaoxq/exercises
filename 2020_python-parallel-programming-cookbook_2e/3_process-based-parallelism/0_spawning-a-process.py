#!/usr/bin/env python

import multiprocessing


def myFunc(i):
    print(f'calling myFunc {i}')


if __name__ == '__main__':
    processes = [multiprocessing.Process(target=myFunc, args=(i,)) for i in range(3)]
    for p in processes:
        p.start()
    for p in processes:
        p.join()
