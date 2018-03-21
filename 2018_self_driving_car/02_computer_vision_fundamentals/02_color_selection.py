#!/usr/bin/env python

import os

import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np

# Read in the image and print out some stats
img_file = os.path.join(os.path.dirname(__file__), 'test.jpg')
image = mpimg.imread(img_file)
print('This image is:', type(image), 'with dimensions:', image.shape)

# Define our color selection criteria
# Note: if you run this code, you'll find these are not sensible values!!
# But you'll get a chance to play with them soon in a quiz
rgb_threshold = [200, 200, 200]
# Identify pixels below the threshold
thresholds = (image[:, :, 0] < rgb_threshold[0]) | \
             (image[:, :, 1] < rgb_threshold[1]) | \
             (image[:, :, 2] < rgb_threshold[2])

# Note: always make a copy rather than simply using "="
color_select = np.copy(image)
color_select[thresholds] = [0, 0, 0]

# Display the image                 
plt.imshow(color_select)
plt.show()
