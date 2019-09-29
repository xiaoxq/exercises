#!/usr/bin/env python

import os

import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np

# Read in the image and print out some stats
img_file = os.path.join(os.path.dirname(__file__), 'test.jpg')
image = mpimg.imread(img_file)
print('This image is:', type(image), 'with dimensions:', image.shape)

# Define a triangle region of interest (Note: if you run this code,
# Keep in mind the origin (x=0, y=0) is in the upper left in image processing
# you'll find these are not sensible values!!
# But you'll get a chance to play with them soon in a quiz ;)
left_bottom = [0, 539]
right_bottom = [960, 539]
apex = [480, 320]

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

# Mask pixels below the threshold
rgb_threshold = [200, 200, 200]
color_thresholds = (image[:, :, 0] < rgb_threshold[0]) | \
    (image[:, :, 1] < rgb_threshold[1]) | \
    (image[:, :, 2] < rgb_threshold[2])
# Mask color selection
color_select = np.copy(image)
color_select[color_thresholds] = [0, 0, 0]
# Find where image is both colored right and in the region
line_image = np.copy(image)
line_image[~color_thresholds & region_thresholds] = [255, 0, 0]

# Display our two output images
plt.imshow(color_select)
plt.imshow(line_image)
plt.show()
