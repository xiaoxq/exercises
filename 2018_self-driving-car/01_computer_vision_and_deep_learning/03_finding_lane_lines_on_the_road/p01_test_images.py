#!/usr/bin/env python
import os

import cv2
import matplotlib.image as mpimg
import numpy as np


def region_of_interest(img, vertices):
    """
    Applies an image mask.
    Only keeps the region of the image defined by the polygon
    formed from `vertices`. The rest of the image is set to black.
    """
    # Define a blank mask to start with
    mask = np.zeros_like(img)

    # Define a 3 channel or 1 channel color to fill the mask with depending on
    # the input image
    if len(img.shape) > 2:
        channel_count = img.shape[2]  # i.e. 3 or 4 depending on your image
        ignore_mask_color = (255,) * channel_count
    else:
        ignore_mask_color = 255
    # Fill pixels inside the polygon defined by "vertices" with the fill color
    cv2.fillPoly(mask, vertices, ignore_mask_color)
    # Return the image only where mask pixels are nonzero
    return cv2.bitwise_and(img, mask)


def draw_lines(img, lines, bgr_color=[0, 0, 255], thickness=2):
    """
    NOTE: this is the function you might want to use as a starting point once
    you want to average/extrapolate the line segments you detect to map out the
    full extent of the lane (going from the result shown in
    raw-lines-example.mp4 to that shown in P1_example.mp4).

    Think about things like separating line segments by their
    slope ((y2-y1)/(x2-x1)) to decide which segments are part of the left
    line vs. the right line.  Then, you can average the position of each of
    the lines and extrapolate to the top and bottom of the lane.

    This function draws `lines` with `color` and `thickness`.
    Lines are drawn on the image inplace (mutates the image).
    If you want to make the lines semi-transparent, think about combining
    this function with the weighted_img() function below
    """
    for line in lines:
        for x1, y1, x2, y2 in line:
            cv2.line(img, (x1, y1), (x2, y2), bgr_color, thickness)


def hough_lines(img, rho, theta, threshold, min_line_len, max_line_gap):
    """
    `img` should be the output of a Canny transform.

    Returns an image with hough lines drawn.
    """
    lines = cv2.HoughLinesP(img, rho, theta, threshold, np.array([]),
                            min_line_len, max_line_gap)
    line_img = np.zeros((img.shape[0], img.shape[1], 3), dtype=np.uint8)
    draw_lines(line_img, lines)
    return line_img


def process_img(img_data):
    """Process an image."""
    gray = cv2.cvtColor(img_data, cv2.COLOR_RGB2GRAY)

    kernel_size = 3
    blur_gray = cv2.GaussianBlur(gray, (kernel_size, kernel_size), 0)

    low_threshold = 50
    high_threshold = 200
    edges = cv2.Canny(blur_gray, low_threshold, high_threshold)

    left_bottom = [0, 539]
    right_bottom = [960, 539]
    apex = [480, 305]
    masked_edges = region_of_interest(
        edges, np.array([[left_bottom, right_bottom, apex]]))

    RHO = 1
    THETA = np.pi / 180
    min_pixel_threshold = 5
    min_line_length = 150
    max_line_gap = 100
    line_img = hough_lines(masked_edges, RHO, THETA, min_pixel_threshold,
                           min_line_length, max_line_gap)
    return cv2.addWeighted(img_data, 0.8, line_img, 1, 0)


if __name__ == '__main__':
    PWD = os.path.dirname(__file__)
    input_dir = os.path.join(PWD, '3rd_CarND-LaneLines-P1/test_images')
    output_dir = os.path.join(PWD, 'test_images_output')
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    for img_file in os.listdir(input_dir):
        img = mpimg.imread(os.path.join(input_dir, img_file))
        cv2.imwrite(os.path.join(output_dir, img_file), process_img(img))
