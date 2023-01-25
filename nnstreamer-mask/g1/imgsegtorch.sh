#!/usr/bin/env bash
gst-launch-1.0 -v \
    filesrc location=./j_scan.mp4 ! decodebin name=dec ! queue ! videoconvert ! \
    videocrop top=490 bottom=360 left=900 right=990 ! aspectratiocrop aspect-ratio=1/1 ! \
    videoscale ! video/x-raw,width=128,height=128 ! \
    tensor_converter ! \
    tensor_transform mode=typecast option=typecast:float32,div:255.0 ! \
    tensor_filter framework=auto model=./torchmodel.pth ! \
    tensor_sink name=tensor_sink
    # autovideosink
    