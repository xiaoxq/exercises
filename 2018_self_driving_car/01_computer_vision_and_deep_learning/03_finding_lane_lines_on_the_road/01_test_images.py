#!/usr/bin/env python
import os

import cv2
import matplotlib.image as mpimg
import numpy as np

import helper


test_images_dir = os.path.join(os.path.dirname(__file__),
                               '3rd_CarND-LaneLines-P1/test_images/')
for img_file in os.listdir(test_images_dir):
    img = mpimg.imread(os.path.join(test_images_dir, img_file))
    gray = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)

    kernel_size = 3
    blur_gray = cv2.GaussianBlur(gray, (kernel_size, kernel_size), 0)

    low_threshold = 50
    high_threshold = 200
    edges = cv2.Canny(blur_gray, low_threshold, high_threshold)

    left_bottom = [0, 539]
    right_bottom = [960, 539]
    apex = [480, 305]
    masked_edges = helper.region_of_interest(
        edges, np.array([[left_bottom, right_bottom, apex]]))

    RHO = 1
    THETA = np.pi / 180
    min_pixel_threshold = 5
    min_line_length = 150
    max_line_gap = 100
    line_img = helper.hough_lines(masked_edges, RHO, THETA, min_pixel_threshold,
                                  min_line_length, max_line_gap)

    combo = cv2.addWeighted(img, 0.8, line_img, 1, 0)
    output_dir = os.path.join(test_images_dir, '../test_images_output')
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
    cv2.imwrite(os.path.join(output_dir, img_file), combo)
