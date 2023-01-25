gst-launch-1.0 -v \
    filesrc location=neck_scan.mp4 ! decodebin name=dec ! queue ! videoconvert ! \
    videocrop top=490 bottom=360 left=900 right=990 ! aspectratiocrop aspect-ratio=1/1 ! \
    video/x-raw,width=256,height=256 ! autovideosink
