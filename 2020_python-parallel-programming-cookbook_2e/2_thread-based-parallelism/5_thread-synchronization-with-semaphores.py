#!/usr/bin/env python

import threading
import time
import random


semaphore = threading.Semaphore(0)
item = 0


def consumer():
    print('Consumer is waiting')
    semaphore.acquire()
    print(f'Consumer notify: item number {item}')


def producer():
    global item
    item = random.randint(0, 1000)
    print(f'Producer notify: item number {item}')
    semaphore.release()


def main():
    for _ in range(10):
        t1 = threading.Thread(target=consumer)
        t2 = threading.Thread(target=producer)

        t1.start()
        t2.start()

        t1.join()
        t2.join()


if __name__ == "__main__":
    main()
