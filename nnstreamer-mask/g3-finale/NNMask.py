import os
import gi
import cairo
from argparse import ArgumentParser

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

class NNMask:
    def __init__(self, argv=None):
        parser = ArgumentParser()
        parser.add_argument('--video', type=str, default='./data/j_scan.mp4', help='input video file path')
        parser.add_argument('--model', type=str, default='./data/unet_tvm_cpu_256.so', help='tvm model file path')
        parser.add_argument('--input_height', type=str, default='256', help='input height')
        parser.add_argument('--input_width', type=str, default='256', help='input width')
        parser.add_argument('--output_height', type=str, default='512', help='output height')
        parser.add_argument('--output_width', type=str, default='512', help='output width')
        parser.add_argument('--crop', type=str, default='490,360,900,990', help='videocrop option [top,bottom,left,right]')
        
        args = parser.parse_args()
        self.g_cnt = 0
        self.tensor_result = None
        self.output_width = args.output_width
        self.output_height = args.output_height
        self.input_width = args.input_width
        self.input_height = args.input_height

        self.crop_option = ''
        if str(args.crop) != '':
            self.crop_option = 'videocrop top={} bottom={} left={} right={} !'.format(*args.crop.split(','))

        self.pipeline_str = \
            'filesrc location={video_path} ! \n' + \
            'decodebin ! videoconvert ! {crop} \n' + \
            'videoscale ! video/x-raw,width={output_width},height={output_height},format=RGB ! tee name=t_raw \n' + \
            't_raw. ! queue ! videoconvert ! cairooverlay name=tensor_res ! ximagesink name=img_tensor \n' + \
            't_raw. ! queue leaky=2 max-size-buffers=2 ! videoscale ! video/x-raw,width={input_width},height={input_height}! \n' + \
            'tensor_converter ! \n' + \
            'tensor_transform mode=arithmetic option=typecast:float32,div:255 ! \n' + \
            'tensor_transform mode=dimchg option=0:2 ! \n' + \
            'tensor_filter framework=tvm model={model_path} input={input_width}:{input_height}:3 inputtype=float32 custom=device:CPU,num_input_tensors:1 ! \n' + \
            'tensor_sink name=tensor_sink'
        self.pipeline_str = self.pipeline_str.format( 
            video_path=args.video, model_path=args.model,
            output_width=self.output_width, output_height=self.output_height,
            input_width=self.input_width, input_height=self.input_height,
            crop=self.crop_option
        )
        Gst.init()

    def new_data_cb(self, sink, buffer):
        if self.running:
            if buffer.n_memory() != 1:
                return False

            buffer_content = buffer.peek_memory(0)
            result, mapinfo_content = buffer_content.map(Gst.MapFlags.READ)
            if result:
                content_arr = np.frombuffer(mapinfo_content.data, dtype=np.float32)
                tensor_result = np.reshape(content_arr, (int(self.input_width), int(self.input_height))) 
                self.tensor_result = tensor_result
                self.g_cnt += 1
                buffer_content.unmap(mapinfo_content)

    def draw_overlay_cb(self, overlay, context, timestamp, duration):
        if self.running:
            try:
                buf = (self.tensor_result > 0.5).astype(np.uint8) * 255
            except:
                return False
            context.set_source_rgb(1.0, 0, 0)
            buf = cv2.resize(buf, dsize=(int(self.output_width),int(self.output_height)))
            source = cairo.ImageSurface.create_for_data(
                buf, cairo.FORMAT_A8, int(self.output_width), int(self.output_height))
            context.mask_surface(source, 0, 0)
            context.fill()

    def run(self):
        print(self.pipeline_str)
        pipeline = Gst.parse_launch(self.pipeline_str)

        tensor_sink = pipeline.get_by_name('tensor_sink')
        tensor_sink.connect('new_data', self.new_data_cb)
        tensor_res = pipeline.get_by_name('tensor_res')
        tensor_res.connect('draw', self.draw_overlay_cb)

        pipeline.set_state(Gst.State.PLAYING)
        self.running = True
        s_time = time.time()

        bus = pipeline.get_bus()
        msg = bus.timed_pop_filtered(
            Gst.CLOCK_TIME_NONE,
            Gst.MessageType.ERROR | Gst.MessageType.EOS
        )

        self.running = False
        time_delta = time.time() - s_time
        print("time :", time_delta)
        print("fps :", self.g_cnt / time_delta)
        pipeline.set_state(Gst.State.NULL)
        bus.remove_signal_watch()


if __name__ == '__main__':
    masker = NNMask()
    masker.run()
