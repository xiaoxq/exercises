#!/usr/bin/env python

import threading


def my_func(thread_number):
    return print(f'my_func called by thread {thread_number}')


def main():
    for i in range(10):
        t = threading.Thread(target=my_func, args=(i,))
        t.start()
        t.join()


if __name__ == "__main__":
    main()
