#!/usr/bin/env python3

from keras.layers.convolutional import Convolution2D
import keras
import numpy as np

from keras_adversarial import AdversarialOptimizerSimultaneous
import keras_adversarial


def gan_targets(sample_num):
    """
    Standard training targets [generator_fake, generator_real,
    discriminator_fake, discriminator_real] = [1, 0, 0, 1]
    """
    generator_fake = np.ones((sample_num, 1))
    generator_real = np.zeros((sample_num, 1))
    discriminator_fake = np.zeros((sample_num, 1))
    discriminator_real = np.ones((sample_num, 1))
    return [generator_fake, generator_real,
            discriminator_fake, discriminator_real]


def model_generator():
    nch = 256
    g_input = keras.layers.Input(shape=[100])
    H = keras.layers.Dense(14 * 14 * nch, init='glorot_normal')(g_input)
    H = keras.layers.BatchNormalization()(H)
    H = keras.layers.Activation('relu')(H)
    H = keras.layers.Reshape(14 * 14 * nch)(H)
    H = keras.layers.convolutional.UpSampling2D(size=(2, 2))(H)
    H = Convolution2D(3, 3, int(nch / 2), border_mode='same', 
                      init='glorot_uniform')(H)
    H = keras.layers.BatchNormalization(axis=1)(H)
    H = keras.layers.Activation('relu')(H)
    H = Convolution2D(3, 3, int(nch / 4), border_mode='same', 
                      init='glorot_uniform')(H)
    H = keras.layers.BatchNormalization(axis=1)(H)
    H = keras.layers.Activation('relu')(H)
    H = Convolution2D(1, 1, 1, border_mode='same', init='glorot_uniform')(H)
    g_V = keras.layers.Activation('sigmoid')(H)
    return keras.models.Model(g_input, g_V)


def model_discriminator(input_shape, dropout_rate=0.5):
    d_input = keras.layers.Input(input_shape, name="input_x")
    nch = 512
    H = Convolution2D(5, 5, int(nch / 2), subsample=(2, 2),
                      border_mode='same', activation='relu')(d_input)
    H = keras.layers.LeakyReLU(0.2)(H)
    H = keras.layers.Dropout(dropout_rate)(H)
    H = Convolution2D(5, 5, nch, subsample=(2, 2),
                      border_mode='same', activation='relu')(H)
    H = keras.layers.LeakyReLU(0.2)(H)
    H = keras.layers.Dropout(dropout_rate)(H)
    H = keras.layers.Flatten()(H)
    H = keras.layers.Dense(int(nch / 2))(H)
    H = keras.layers.LeakyReLU(0.2)(H)
    H = keras.layers.Dropout(dropout_rate)(H)
    d_V = keras.layers.Dense(1, activation='sigmoid')(H)
    return keras.models.Model(d_input, d_V)


def generator_sampler():
    zsamples = np.random.normal(size=(10 * 10, latent_dim))
    gen = dim_ordering_unfix(generator.predict(zsamples))
    return gen.reshape((10, 10, 28, 28))


def GetData():
    """Return X_train, Y_train, X_test, Y_test"""
    (X_train, y_train), (X_test, y_test) = keras.datasets.mnist.load_data()
    # X_train is 60000 rows of 28x28 values. Reshape and normalize.
    X_train = X_train.astype('float32') / 255
    # X_test is 10000 rows of 28x28 values.
    X_test = X_test.astype('float32') / 255
    return X_train.reshape(-1, 28, 28, 1), X_test.reshape(-1, 28, 28, 1)


if __name__ == "__main__":
    # z in R^100
    latent_dim = 100
    # generator (z -> x)
    generator = model_generator()
    # discriminator (x -> y)
    discriminator = model_discriminator(input_shape=(28, 28, 1))
    # gan (x - > yfake, yreal), z generated on GPU
    gan = keras_adversarial.simple_gan(
        generator, discriminator,
        keras_adversarial.normal_latent_sampling((latent_dim,)))

    # build adversarial model
    model = keras_adversarial.AdversarialModel(
        base_model=gan,
        player_params=[generator.trainable_weights,
                       discriminator.trainable_weights],
        player_names=["generator", "discriminator"])
    model.adversarial_compile(
        adversarial_optimizer=AdversarialOptimizerSimultaneous(),
        player_optimizers=[keras.optimizers.Adam(1e-4, decay=1e-4),
                           keras.optimizers.Adam(1e-3, decay=1e-4)],
        loss='binary_crossentropy')

    generator_cb = keras_adversarial.ImageGridCallback(
        "output/gan_convolutional/epoch-{:03d}.png", generator_sampler)
    X_train, X_test = GetData()
    Y_train = gan_targets(X_train.shape[0])
    Y_test = gan_targets(X_test.shape[0])
    model.fit(x=X_train, y=Y_train,
              validation_data=(X_test, Y_test), callbacks=[generator_cb],
              nb_epoch=100, batch_size=32)
