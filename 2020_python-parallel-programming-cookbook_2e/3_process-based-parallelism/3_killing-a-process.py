#!/usr/bin/env python

import multiprocessing
import time


def foo():
    while True:
        time.sleep(1)


if __name__ == '__main__':
    p = multiprocessing.Process(target=foo)
    p.start()
    print(f'p.is_alive = {p.is_alive()}')
    p.terminate()
    p.join()
    print(f'p.is_alive = {p.is_alive()}')
    print(f'Process exits with {p.exitcode}')
