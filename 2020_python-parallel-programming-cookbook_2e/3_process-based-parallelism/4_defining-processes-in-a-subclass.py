#!/usr/bin/env python

import multiprocessing


class MyProcess(multiprocessing.Process):
    def run(self):
        print ('MyProcess')


if __name__ == '__main__':
    process = MyProcess()
    process.start()
    process.join()
