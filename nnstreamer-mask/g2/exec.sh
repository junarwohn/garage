#gst-launch-1.0 videotestsrc num-buffers=100 ! videoconvert ! videoscale ! video/x-raw,format=RGB,width=256,height=256 ! tensor_converter ! tensor_transform mode=arithmetic option=typecast:float32,div:255 ! tensor_filter framework=tvm model=/home/j/paarthurnax/g2/unet_tvm.so custom=device:CPU,num_input_tensors:1 ! tensor_sink name=sink

gst-launch-1.0 videotestsrc num-buffers=100 ! videoconvert ! videoscale ! video/x-raw,format=RGB,width=256,height=256 ! tensor_converter ! tensor_transform mode=arithmetic option=typecast:float32,div:255 ! tensor_transform mode=dimchg option=0:2 ! tensor_filter framework=tvm model=/home/j/paarthurnax/g2/unet_tvm.so  custom=device:CPU,num_input_tensors:1 ! tensor_sink name=sink
