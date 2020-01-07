#!/usr/bin/env python

import multiprocessing
import random
import time


queue = multiprocessing.Queue()


class Producer(multiprocessing.Process):
    def run(self):
        for _ in range(10):
            item = random.randint(0, 256)
            queue.put(item)
            print(f"Producer: item {item} appended to queue by {self.name}")
        queue.put(None)


class Consumer(multiprocessing.Process):
    def run(self):
        while True:
            item = queue.get()
            if item is None:
                queue.put(None)
                break
            time.sleep(random.uniform(0, 1))
            print(f'Consumer: item {item} popped by {self.name}')


if __name__ == '__main__':
    processes = [Producer(), Consumer(), Consumer()]
    for p in processes:
        p.start()
    for p in processes:
        p.join()
