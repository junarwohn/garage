#!/usr/bin/env bash
#tensor_filter framework=tensorflow-lite model=data/unet.tflite ! \
gst-launch-1.0 \
    videomixer name=mix sink_0::alpha=1.0 sink_1::alpha=0.6 ! aspectratiocrop aspect-ratio=16/9 ! videoconvert ! autovideosink sync=false \
    filesrc location=neck_scan.mp4 ! decodebin name=dec ! videoconvert ! \
    videocrop top=490 bottom=360 left=900 right=990 ! aspectratiocrop aspect-ratio=1/1 ! \
    videoscale ! video/x-raw,width=256,height=256 ! tee name=t \
    t. ! queue ! mix. \
    t. ! queue ! tensor_converter ! \
    tensor_transform mode=arithmetic option=typecast:float32,div:255.0 ! \
    tensor_filter framework=pytorch model=data/unet_210623.pth ! \
    tensor_decoder mode=image_segment option1=snpe-depth ! mix. 
