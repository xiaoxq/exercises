#!/usr/bin/env python
import os

from moviepy.editor import VideoFileClip

import p01_test_images


if __name__ == '__main__':
    PWD = os.path.dirname(__file__)
    input_dir = os.path.join(PWD, '3rd_CarND-LaneLines-P1/test_videos')
    output_dir = os.path.join(PWD, 'test_videos_output')
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    for video in os.listdir(input_dir):
        f_in = os.path.join(input_dir, video)
        f_out = os.path.join(output_dir, video) + '.webm'
        VideoFileClip(f_in) \
            .fl_image(p01_test_images.process_img) \
            .write_videofile(f_out, codec='libvpx', audio=False)
