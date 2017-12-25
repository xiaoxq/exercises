#!/usr/bin/env python3

from keras.layers import Dense, Reshape, Flatten, Dropout, LeakyReLU, Input, Activation, BatchNormalization
from keras.models import Sequential, Model
from keras.layers.convolutional import Convolution2D, UpSampling2D
from keras.optimizers import Adam
from keras.regularizers import l1, l1l2
from keras.datasets import mnist

import pandas as pd
import numpy as np

from keras_adversarial import AdversarialModel, ImageGridCallback, simple_gan, gan_targets
from keras_adversarial import AdversarialOptimizerSimultaneous, normal_latent_sampling, AdversarialOptimizerAlternating
from image_utils import dim_ordering_fix, dim_ordering_input, dim_ordering_reshape, dim_ordering_unfix


