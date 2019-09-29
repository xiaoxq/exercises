#!/usr/bin/env python

import os

import cv2
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np

# Read in the image and print out some stats
img_file = os.path.join(os.path.dirname(__file__), 'exit-ramp.jpg')
image = mpimg.imread(img_file)
print('This image is:', type(image), 'with dimensions:', image.shape)

# Define a triangle region of interest (Note: if you run this code,
# Keep in mind the origin (x=0, y=0) is in the upper left in image processing
# you'll find these are not sensible values!!
# But you'll get a chance to play with them soon in a quiz ;)
left_bottom = [0, 539]
right_bottom = [960, 539]
apex = [480, 275]

fit_left = np.polyfit((left_bottom[0], apex[0]), (left_bottom[1], apex[1]), 1)
fit_right = np.polyfit((right_bottom[0], apex[0]),
                       (right_bottom[1], apex[1]), 1)
fit_bottom = np.polyfit((left_bottom[0], right_bottom[0]),
                        (left_bottom[1], right_bottom[1]), 1)

# Find the region inside the lines
ysize = image.shape[0]
xsize = image.shape[1]
XX, YY = np.meshgrid(np.arange(0, xsize), np.arange(0, ysize))
region_thresholds = (YY > (XX * fit_left[0] + fit_left[1])) & \
                    (YY > (XX * fit_right[0] + fit_right[1])) & \
                    (YY < (XX * fit_bottom[0] + fit_bottom[1]))

# Convert to gray image.
gray = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)

# Define a kernel size for Gaussian smoothing
# Note: this step is optional as cv2.Canny() applies a 5x5 Gaussian internally
kernel_size = 3
blur_gray = cv2.GaussianBlur(gray, (kernel_size, kernel_size), 0)

# Define parameters for Canny and run it
low_threshold = 50
high_threshold = 200
edges = cv2.Canny(blur_gray, low_threshold, high_threshold)

# Define the Hough transform parameters
# Make a blank the same size as our image to draw on
RHO = 1
THETA = np.pi / 180
min_pixel_threshold = 5
min_line_length = 65
max_line_gap = 45

# Run Hough on edge detected image
masked_edges = np.copy(edges)
masked_edges[~region_thresholds] = 0
lines = cv2.HoughLinesP(masked_edges, RHO, THETA, min_pixel_threshold,
                        np.array([]), min_line_length, max_line_gap)

# Iterate over the output "lines" and draw lines on the blank
line_image = np.copy(image) * 0  # creating a blank to draw lines on
for line in lines:
    for x1, y1, x2, y2 in line:
        cv2.line(line_image, (x1, y1), (x2, y2), (255, 0, 0), 10)

# Create a "color" binary image to combine with line image
color_edges = np.dstack((edges, edges, edges))
# Draw the lines on the edge image
combo = cv2.addWeighted(color_edges, 0.8, line_image, 1, 0)
plt.imshow(combo)
plt.show()
