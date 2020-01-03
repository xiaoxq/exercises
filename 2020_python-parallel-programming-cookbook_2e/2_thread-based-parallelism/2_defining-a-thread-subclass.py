#!/usr/bin/env python

import time
import os
from threading import Thread


class MyThreadClass(Thread):
    def __init__(self, name):
        Thread.__init__(self)
        self.name = name

    def run(self):
        print(f"{self.name} running, belonging to process ID {os.getpid()}")
        time.sleep(2)
        print(f"{self.name} over")


def main():
    t = MyThreadClass("MyThread")
    t.start()
    t.join()


if __name__ == "__main__":
    main()
