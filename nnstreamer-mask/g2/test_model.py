import tensorflow as tf

def new_model():
    input_layer = tf.keras.layers.Input(shape=(128,128,3))
    out = tf.keras.layers.Conv2D(3,3,1,padding='same',name='output')(input_layer)
    model = tf.keras.models.Model(inputs=input_layer,outputs=out)
    print(model.summary())
    return model

oo = new_model()
oo.save("new_model", save_format='pb')
