#####!/usr/bin
#/env python


import os
#os.environ["CUDA_DEVICE_ORDER"]="PCI_BUS_ID"

#os.environ["CUDA_VISIBLE_DEVICES"]="0"
#os.environ["TF_FORCE_GPU_ALLOW_GROWTH"] = "true"
#os.environ["CUDA_VISIBLE_DEVICES"] = '0'

import gi
import cairo

gi.require_version('GLib', '2.0')
gi.require_version('GObject', '2.0')
gi.require_version('Gst', '1.0')
gi.require_version('Gtk', '3.0')
gi.require_version('GstVideo', '1.0')
from gi.repository import Gst
from gi.repository import Gtk
from gi.repository import GObject, GstVideo, GLib
import sys
import cv2
import numpy as np
import time
gi.require_foreign('cairo')

Gst.init(sys.argv[1:])
tensor_result = np.array([])
g_cnt = 0
g_data = 0
g_buffer_content = 0
g_tensor_result = 0
def new_data_cb(sink, buffer):
    global g_cnt
    global tensor_result
    global g_data
    global g_buffer_content
    global g_tensor_result
    print("new_data_cb : ", running)
    if running:
        #print(buffer.n_memory())
        buffer_content = buffer.get_memory(0)
        g_buffer_content = buffer_content
        result, mapinfo_content = buffer_content.map(Gst.MapFlags.READ)
        #print(result, mapinfo_content)
        g_data = mapinfo_content
        if result:
           content_arr = np.frombuffer(mapinfo_content.data, dtype=np.float32)
           tensor_result = np.reshape(content_arr, (128, 128)) 
           g_tensor_result = tensor_result
           #cv2.imwrite('./result/img_{}.png'.format(g_cnt), np.reshape(content_arr, (-1, 128))*255)
           g_cnt += 1
        # if result:
        #     if mapinfo_content.size == expected_size * 4:
        #         content_arr = np.frombuffer(mapinfo_content.data, dtype=data_type)
        #         buffer_content.unmap(mapinfo_content)

        #         if model_name.find('yolo') > 0:
        #             return np.reshape(content_arr, (-1, 85))
        #         else:
        #             return content_arr

        # else:
        #     buffer_content.unmap(mapinfo_content)
        #     print(f'''Error: getting memory from buffer with index {idx} failed''')
        #     exit(1)
        # print('[tensor_sink] new data cb called')

def draw_overlay_cb(overlay, context, timestamp, duration):
    global g_data
    print("draw_overlay_cb ", running)
    print(g_tensor_result.shape)
    if running:
    #if running:
        buf = (g_tensor_result > 0.5).astype(np.uint8) * 255
        context.set_source_rgb(1.0, 0, 0)
        print("buf shape", buf.shape)
        buf = cv2.resize(buf, dsize=(512,512))
        source = cairo.ImageSurface.create_for_data(
            buf, cairo.FORMAT_A8, 512, 512)
        #source = cairo.ImageSurface.create_for_data(
        #    buf, cairo.FORMAT_A8, 128, 128)
        context.mask_surface(source, 0, 0)
        context.fill()

# width, height = 255, 255
# data = np.ndarray(shape=(height, width), dtype=np.uint32)

# for y in range(height):
#     for x in range(width):
#         alpha = y
#         b = int(x * alpha / 255.0)
#         g = int(y * alpha / 255.0)
#         data[y][x] = (b | g << 8 | alpha << 24)

# surface = cairo.ImageSurface.create_for_data(
#     data, cairo.FORMAT_ARGB32, width, height)


#pipeline_str = \
#    'filesrc location=/home/j/paarthurnax/g2/j_scan.mp4 ! \
#    decodebin ! videoconvert ! videocrop top=490 bottom=360 left=900 right=990 ! videoscale ! video/x-raw,width=128,height=128,format=RGB ! tee name=t_raw \
#        t_raw. ! queue ! videoconvert ! cairooverlay name=tensor_res ! ximagesink name=img_tensor \
#        t_raw. ! queue leaky=2 max-size-buffers=2 ! videoscale ! video/x-raw,width=128,height=128 ! \
#            tensor_converter ! tensor_transform mode=arithmetic option=typecast:float32,div:255 ! \
#            tensor_filter framework=tensorflow2-lite model=/home/j/paarthurnax/g2/unet.tflite ! \
#            tensor_sink name=tensor_sink'


pipeline_str = \
    'filesrc location=/home/j/paarthurnax/g2/j_scan.mp4 ! \
    decodebin ! videoconvert ! videocrop top=490 bottom=360 left=900 right=990 ! \
    videoscale ! video/x-raw,width=512,height=512,format=RGB ! tee name=t_raw \
    t_raw. ! queue ! videoconvert ! cairooverlay name=tensor_res ! decodebin ! x264enc ! mp4mux ! filesink location=file.mp4 \
    t_raw. ! queue leaky=2 max-size-buffers=2 ! videoscale ! video/x-raw,width=128,height=128! \
    tensor_converter ! \
    tensor_transform mode=arithmetic option=typecast:float32,div:255 ! \
    tensor_transform mode=dimchg option=0:2 ! \
    tensor_filter framework=tvm model=/home/j/paarthurnax/g2/unet_tvm_cpu.so input=128:128:3 inputtype=float32 custom=device:CPU,num_input_tensors:1 ! \
    tensor_sink name=tensor_sink'



pipeline = Gst.parse_launch(pipeline_str)

tensor_sink = pipeline.get_by_name('tensor_sink')
tensor_sink.connect('new_data', new_data_cb)
tensor_res = pipeline.get_by_name('tensor_res')
tensor_res.connect('draw', draw_overlay_cb)

pipeline.set_state(Gst.State.PLAYING)
s_time = time.time()
running = True

bus = pipeline.get_bus()
msg = bus.timed_pop_filtered(
    Gst.CLOCK_TIME_NONE,
    Gst.MessageType.ERROR | Gst.MessageType.EOS
)

running = False
time_delta = time.time() - s_time
print("time :", time_delta)
print("fps :", g_cnt / time_delta)
print(g_cnt)
pipeline.set_state(Gst.State.NULL)
