#!/usr/bin/env bash
gst-launch-1.0 -v \
    videomixer name=mix sink_0::alpha=1.0 sink_1::alpha=0.6 ! aspectratiocrop aspect-ratio=16/9 ! videoconvert ! autovideosink sync=false \
    filesrc location=/home/j/paarthurnax/g2/vid.webm ! decodebin ! videoconvert ! videoscale ! \
    video/x-raw,format=RGB,width=257,height=257 ! tee name=t \
    t. ! queue ! mix. \
    t. ! queue ! tensor_converter ! \
        tensor_transform mode=arithmetic option=typecast:float32,div:255.0 ! \
        tensor_filter framework=tensorflow2-lite model=/home/j/paarthurnax/g2/unet.tflite ! \
        tensor_decoder mode=image_segment option1=tflite-deeplab ! mix.
