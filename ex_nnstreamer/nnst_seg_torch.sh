gst-launch-1.0 -v \
   filesrc location=data/test.png ! decodebin ! videoconvert ! videoscale ! imagefreeze !\
   video/x-raw,format=RGB,width=256,height=256,framerate=10/1 ! tee name=t \
   t. ! queue ! mix. \
   t. ! queue ! tensor_converter !\
   tensor_transform mode=arithmetic option=typecast:float32,add:0.0,div:255.0 !\
   tensor_filter framework=tensorflow2-lite model=data/unet.tflite !\
   tensor_decoder mode=image_segment option1=tflite-deeplab option2=2 ! mix.\
   videomixer name=mix sink_0::alpha=0.7 sink_1::alpha=0.6 ! videoconvert !  videoscale ! autovideosink \
