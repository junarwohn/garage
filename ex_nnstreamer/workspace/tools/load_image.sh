gst-launch-1.0 -v \
    filesrc location=data/test.png ! decodebin ! videoconvert ! videoscale ! imagefreeze !\
   video/x-raw,format=RGB,width=257,height=257,framerate=10/1 ! videoconvert ! videoscale ! autovideosink 
