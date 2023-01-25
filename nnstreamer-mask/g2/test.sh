gst-launch-1.0 filesrc location=/home/j/paarthurnax/g2/vid.webm ! decodebin ! videoconvert ! videoscale ! video/x-raw,width=128,height=128,format=RGB ! tee name=t_raw \
    t_raw. ! queue ! videoconvert ! cairooverlay name=tensor_res ! ximagesink name=img_tensor \
    t_raw. ! queue leaky=2 max-size-buffers=2 ! videoscale ! video/x-raw,width=128,height=128 ! tensor_converter ! \
    tensor_transform mode=arithmetic option=typecast:float32,div:255 ! \
    tensor_filter framework=tensorflow2-lite model=/home/j/paarthurnax/g2/unet.tflite ! \
    tensor_sink name=tensor_sink


gst-launch-1.0 filesrc location=/home/j/paarthurnax/g2/vid.webm ! decodebin ! videoconvert ! videoscale ! video/x-raw,width=128,height=128,format=RGB  !  videoconvert ! cairooverlay name=tensor_res ! ximagesink name=img_tensor
gst-launch-1.0 filesrc location=/home/j/paarthurnax/g2/vid.webm ! decodebin ! videoconvert ! videoscale ! video/x-raw,width=128,height=128,format=RGB ! tee name=t_raw  t_raw. ! queue ! videoconvert ! cairooverlay name=tensor_res ! ximagesink name=img_tensor 
gst-launch-1.0 filesrc location=/home/j/paarthurnax/g2/vid.webm ! decodebin ! videoconvert ! videoscale ! video/x-raw,width=128,height=128,format=RGB ! tee name=t_raw  t_raw. ! queue leaky=2 max-size-buffers=2 ! videoscale ! video/x-raw,width=128,height=128 ! tensor_converter ! tensor_transform mode=arithmetic option=typecast:float32,add:-127.5,div:127.5 ! tensor_filter framework=tensorflow2-lite model=/home/j/paarthurnax/g2/unet.tflite ! tensor_sink name=tensor_sink

gst-launch-1.0 filesrc location=/home/j/paarthurnax/g2/vid.webm ! decodebin ! videoconvert ! videoscale ! video/x-raw,width=128,height=128,format=RGB ! tee name=t_raw t_raw. ! queue ! videoconvert ! cairooverlay name=tensor_res ! ximagesink name=img_tensor t_raw. ! queue leaky=2 max-size-buffers=2 ! videoscale ! video/x-raw,width=128,height=128 ! tensor_converter ! tensor_transform mode=arithmetic option=typecast:float32,div:255 ! tensor_filter framework=tensorflow2-lite model=/home/j/paarthurnax/g2/unet.tflite ! tensor_sink name=tensor_sink