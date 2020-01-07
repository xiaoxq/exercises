#!/usr/bin/env python

import multiprocessing


def create_items(pipe_1):
    send_pipe, _ = pipe_1
    for item in range(10):
        send_pipe.send(item)
    send_pipe.close()


def multiply_items(pipe_1, pipe_2):
    to_close, recv_pipe = pipe_1
    to_close.close()

    send_pipe, _ = pipe_2
    try:
        while True:
            item = recv_pipe.recv()
            send_pipe.send(item * item)
    except EOFError:
        recv_pipe.close()


if __name__== '__main__':
    pipe_1 = multiprocessing.Pipe(duplex=True)
    process_pipe_1 = multiprocessing.Process(target=create_items, args=(pipe_1,))
    process_pipe_1.start()

    pipe_2 = multiprocessing.Pipe(duplex=True)
    process_pipe_2 = multiprocessing.Process(target=multiply_items, args=(pipe_1, pipe_2,))
    process_pipe_2.start()

    pipe_1[0].close()
    pipe_2[0].close()

    try:
        while True:
            print(pipe_2[1].recv())
    except EOFError:
        print("End")
