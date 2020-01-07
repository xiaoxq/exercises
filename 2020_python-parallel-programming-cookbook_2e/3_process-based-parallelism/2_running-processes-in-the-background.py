#!/usr/bin/env python

import multiprocessing


def background_process():
    print('background_process')


def foreground_process():
    print('foreground_process')


if __name__ == '__main__':
    multiprocessing.Process(target=foreground_process, daemon=False).start()
    multiprocessing.Process(target=background_process, daemon=True).start()
