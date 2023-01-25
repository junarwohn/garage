import tensorflow as tf
from tensorflow.keras import datasets, layers, models
import keras


def Net(shape):
    input_layer = layers.Input(shape=shape)
    out = layers.Conv2D(filters=16, kernel_size=3, strides=1, padding='same')(input_layer)
    out = layers.MaxPool2D(pool_size=(2,2), strides=2, padding='same')(out)
    out = layers.Conv2D(filters=32, kernel_size=3, strides=1, padding='same')(out)
    out = layers.MaxPool2D(pool_size=(2,2), strides=2, padding='same')(out)
    # out = layers.Conv2D(filters=64, kernel_size=3, strides=1, padding='same')(out)
    # out = layers.MaxPool2D(pool_size=(2,2), strides=2, padding='same')(out)
    # out = layers.Conv2D(filters=128, kernel_size=3, strides=1, padding='same')(out)
    # out = layers.MaxPool2D(pool_size=(2,2), strides=2, padding='same')(out)
    model = keras.models.Model(inputs=input_layer, outputs=out)
    return model