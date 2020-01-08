#!/usr/bin/env python

import concurrent.futures
import time


def count(number):
    for i in range(1_000_000):
        number += 1
    return number


if __name__ == '__main__':
    numbers = list(range(10))
    start_time = time.process_time()
    for item in numbers:
        count(item)
    print(f'Sequential Execution in {time.process_time() - start_time} seconds')

    start_time = time.process_time()
    with concurrent.futures.ThreadPoolExecutor(max_workers=5) as executor:
        for item in numbers:
            executor.submit(count, item)
    print(f'Thread Pool Execution in {time.process_time() - start_time} seconds')

    start_time = time.process_time()
    with concurrent.futures.ProcessPoolExecutor(max_workers=5) as executor:
        for item in numbers:
            executor.submit(count, item)
    print(f'Process Pool Execution in {time.process_time() - start_time} seconds')
