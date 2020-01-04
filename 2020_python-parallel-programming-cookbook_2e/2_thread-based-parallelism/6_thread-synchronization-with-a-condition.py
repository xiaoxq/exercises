#!/usr/bin/env python

import threading
import time

items = []
condition = threading.Condition()


class Consumer(threading.Thread):
    def consume(self):
        with condition:
            if len(items) == 0:
                print('no items to consume')
                condition.wait()
            items.pop()
            print('consumed 1 item')
            condition.notify()

    def run(self):
        for _ in range(20):
            time.sleep(1)
            self.consume()


class Producer(threading.Thread):
    def produce(self):
        with condition:
            if len(items) == 5:
                print(f'items produced {len(items)}. Stopped')
                condition.wait()
            items.append(1)
            print(f'total items {len(items)}')
            condition.notify()

    def run(self):
        for _ in range(20):
            time.sleep(0.5)
            self.produce()


def main():
    t1 = Consumer()
    t2 = Producer()

    t1.start()
    t2.start()

    t1.join()
    t2.join()


if __name__ == "__main__":
    main()
