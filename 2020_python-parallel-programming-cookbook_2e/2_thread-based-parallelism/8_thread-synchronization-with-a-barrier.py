#!/usr/bin/env python

from random import randrange
from threading import Barrier, Thread
from time import ctime, sleep


num_runners = 3
finish_line = Barrier(num_runners)
runners = ['Huey', 'Dewey', 'Louie']


def runner():
    name = runners.pop()
    sleep(randrange(2, 5))
    print(f'{name} reached the barrier at: {ctime()}')
    finish_line.wait()


def main():
    threads = [Thread(target=runner) for _ in range(num_runners)]
    print('START RACE!!!!')
    for t in threads:
        t.start()
    for t in threads:
        t.join()
    print('Race over!')


if __name__ == "__main__":
    main()
