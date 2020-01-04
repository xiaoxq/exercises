#!/usr/bin/env python

import threading
import time


class Box:
    def __init__(self):
        self.lock = threading.RLock()
        self.total_items = 0

    def execute(self, value):
        with self.lock:
            self.total_items += value

    def add(self):
        with self.lock:
            self.execute(1)

    def remove(self):
        with self.lock:
            self.execute(-1)


def adder(box, items):
    print("{} items to ADD \n".format(items))
    while items:
        box.add()
        items -= 1
        print(f"ADDED one item -->{items} item to ADD")


def remover(box, items):
    print("{} items to REMOVE\n".format(items))
    while items:
        box.remove()
        items -= 1
        print(f"REMOVED one item -->{items} item to REMOVE")


def main():
    items = 10
    box = Box()

    t1 = threading.Thread(target=adder, args=(box, items))
    t2 = threading.Thread(target=remover, args=(box, items))

    t1.start()
    t2.start()

    t1.join()
    t2.join()


if __name__ == "__main__":
    main()
