#!/usr/bin/env python

import threading
import time
import random


items = []
event = threading.Event()


class Consumer(threading.Thread):
    def run(self):
        while True:
            time.sleep(2)
            event.wait()
            item = items.pop()
            print(f'Consumer notify: {item} popped by {self.name}')


class Producer(threading.Thread):
    def run(self):
        for _ in range(5):
            time.sleep(2)
            item = random.randint(0, 100)
            items.append(item)
            print(f'Producer notify: item {item} appended by {self.name}')
            event.set()
            event.clear()


def main():
    t1 = Consumer()
    t2 = Producer()

    t1.start()
    t2.start()

    t1.join()
    t2.join()


if __name__ == "__main__":
    main()
