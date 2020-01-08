#!/usr/bin/env python

import asyncio
import random
import time


def task_A(end_time, loop):
    print ("task_A called")
    if (loop.time() + 1.0) < end_time:
        loop.call_later(random.uniform(0, 1), task_B, end_time, loop)
    else:
        loop.stop()


def task_B(end_time, loop):
    print ("task_B called ")
    if (loop.time() + 1.0) < end_time:
        loop.call_later(random.uniform(0, 1), task_C, end_time, loop)
    else:
        loop.stop()


def task_C(end_time, loop):
    print ("task_C called")
    if (loop.time() + 1.0) < end_time:
        loop.call_later(random.uniform(0, 1), task_A, end_time, loop)
    else:
        loop.stop()


if __name__ == '__main__':
    loop = asyncio.get_event_loop()
    end_loop = loop.time() + 10
    loop.call_soon(task_A, end_loop, loop)
    loop.run_forever()
    loop.close()
