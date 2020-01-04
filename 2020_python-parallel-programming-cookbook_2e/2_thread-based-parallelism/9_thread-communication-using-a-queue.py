#!/usr/bin/env python

from threading import Thread
from queue import Queue
import time
import random


queue = Queue()


class Producer(Thread):
    def run(self):
        global queue
        for _ in range(5):
            item = random.randint(0, 256)
            queue.put(item)
            print(f'Producer notify : item {item} appended to queue')
            time.sleep(1)


class Consumer(Thread):
    def run(self):
        global queue
        while True:
            item = queue.get()
            print(f'Consumer notify : {item} popped from queue')
            queue.task_done()


if __name__ == '__main__':
    threads = [Producer(), Consumer(), Consumer(), Consumer()]
    for t in threads:
        t.start()
    for t in threads:
        t.join()
