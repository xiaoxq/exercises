#!/usr/bin/env python

import threading
import time


def function_A():
    print(threading.currentThread().getName() + '--> starting')
    time.sleep(2)
    print(threading.currentThread().getName() + '--> exiting')


def main():
    t = threading.Thread(name='function_A', target=function_A)
    t.start()
    t.join()


if __name__ == "__main__":
    main()
