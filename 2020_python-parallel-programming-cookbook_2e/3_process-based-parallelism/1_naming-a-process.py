#!/usr/bin/env python

import multiprocessing


def myFunc():
    name = multiprocessing.current_process().name
    print(F"Starting process name = {name}")


if __name__ == '__main__':
    processes = [
        multiprocessing.Process(target=myFunc),
        multiprocessing.Process(name='myFunc process', target=myFunc),
    ]

    for p in processes:
        p.start()
    for p in processes:
        p.join()
