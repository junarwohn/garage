abs_path=$(pwd);
gst-launch-1.0 filesrc location=${abs_path}/../../data/vid.webm ! decodebin name=dec ! videoconvert ! autovideosink 
