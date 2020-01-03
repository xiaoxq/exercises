#!/usr/bin/env python

import threading
import time
import os
from threading import Thread


i = 0
threadLock = threading.Lock()


class MyThreadClass(Thread):
    def __init__(self):
        Thread.__init__(self)

    def run(self):
        global i
        with threadLock:
            i += 1


def main():
    threads_num = 100
    threads = [MyThreadClass() for t in range(threads_num)]
    for t in threads:
        t.start()
    for t in threads:
        t.join()
    global i
    print(f"{i} == {threads_num}")


if __name__ == "__main__":
    main()
