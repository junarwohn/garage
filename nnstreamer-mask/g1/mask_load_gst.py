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

Gst.init(sys.argv[1:])


def set_window_title(name, title):
    """Set window title.
    :param name: GstXImageasink element name
    :param title: window title
    :return: None
    """
    element = pipeline.get_by_name(name)
    if element is not None:
        pad = element.get_static_pad('sink')
        if pad is not None:
            tags = Gst.TagList.new_empty()
            tags.add_value(Gst.TagMergeMode.APPEND, 'title', title)
            pad.send_event(Gst.Event.new_tag(tags))


def draw_overlay_cb(overlay, context, timestamp, duration):
    if not running:
        return
    
    draw_cnt = 0
    context.select_font_face('Sans', cairo.FONT_SLANT_NORMAL, cairo.FONT_WEIGHT_NORMAL)
    context.set_font_size(20)
    context.set_line_width(2.0)
    context.set_source_rgb(0.1, 1.0, 0.8)
    source = cairo.ImageSurface.create_from_png('./penguin.png')
    
    im_pen = cv2.imread('./penguin.png', 0)
    # print(im_pen.shape)
    # source = cairo.ImageSurface.create_for_data(cairo.Format.RGB24, np.array(im_pen).astype(np.uint8), len(im_pen), len(im_pen[0]))
    
    width, height = im_pen.shape
    # data = numpy.ndarray(shape=(height, width), dtype=numpy.uint32)
    data = im_pen.astype(np.uint8)

    source = cairo.ImageSurface.create_for_data(
        data, cairo.FORMAT_A8, height, width)

    context.mask_surface(source, 0, 0)

    # pattern = cairo.SurfacePattern(source)
    # pattern.set_extend(cairo.Extend.REPEAT)    
    # context.rectangle(0, 0, 512, 512)
    # context.set_source(pattern)
    context.fill()
    
    """
    # bboxes: [x_min, y_min, x_max, y_max, probability, cls_id] format coordinates.
    for detected_object in self.bboxes:
        score = detected_object[4]
        if score < 0.3:
            continue

        x = int(detected_object[0])
        y = int(detected_object[1])
        width = int(detected_object[2]) - x
        height = int(detected_object[3]) - y

        label_idx = int(detected_object[5])
        label = self.labels[label_idx]
    
        # box_color = self.colors[label_idx]
        # context.set_source_rgb(*box_color)

        # draw rectangle
        context.rectangle(x, y, width, height)
        context.stroke()

        # draw title
        context.move_to(x - 1, y - 8)
        context.show_text('%s  %.2f' % (label, score))

        draw_cnt += 1
        # if draw_cnt >= self.max_object_detection:
        #     break

    # logging performance
    self.times.append(time.time())
    rendered_frames = self.fps_sink.get_property('frames-rendered')
    self.frames.append(rendered_frames)

    if len(self.frames) >= 2 :
        cur_time = time.time() - self.start_time
        latency = self.tensor_filter.get_property('latency') / 1000 / 10
        throughput = self.tensor_filter.get_property('throughput')
        estimated_fps = (self.frames[-1] - self.frames[-2]) / (self.times[-1] - self.times[-2])

        self.perf_data.append([cur_time, len(self.bboxes), draw_cnt, self.fps, self.avgfps, latency, throughput])

    if self.draw_gt_box:
        context.set_line_width(2.0)
        context.set_source_rgb(1.0, 1.0, 0.)

        for gt_object in self.gt_objects[str(self.frame)]:
            x = gt_object.x
            y = gt_object.y
            width = gt_object.width
            height = gt_object.height
            # label = gt_object.class_name

            # draw rectangle
            context.rectangle(x, y, width, height)
            context.stroke()

            # draw title
            # context.move_to(x - 1, y - 8)
            # context.show_text('%s  %.2f' % (label))

            # draw_cnt += 1
            # if draw_cnt >= self.max_object_detection:
            #     break
"""
    

# pipeline = 'filesrc location=./vid.webm ! decodebin name=dec ! aspectratiocrop aspect-ratio=1/1  ! videoconvert ! videoscale  ! video/x-raw,width=512,height=512   ! cairooverlay name=tensor_res ! autovideosink'
# pipeline = 'filesrc location=./j_scan.mp4 ! decodebin name=dec ! aspectratiocrop aspect-ratio=1/1  ! videoconvert ! videoscale  ! video/x-raw,width=512,height=512   ! cairooverlay name=tensor_res ! autovideosink'

#pipeline = 'filesrc location=./j_scan.mp4 ! decodebin name=dec ! aspectratiocrop aspect-ratio=1/1  ! videoconvert ! videoscale  ! video/x-raw,width=512,height=512  ! ximagesink'
pipeline = 'filesrc location=./vid.webm ! decodebin name=dec ! aspectratiocrop aspect-ratio=1/1  ! videoconvert ! videoscale  ! video/x-raw,width=512,height=512  ! ximagesink'
print(Gst)

# loop = GLib.MainLoop()
pipeline = Gst.parse_launch(pipeline)
src_vid = pipeline.get_by_name('dec')
print(type(src_vid))
tensor_res = pipeline.get_by_name('tensor_res')
print(type(tensor_res))
# tensor_res.connect('draw', draw_overlay_cb)


pipeline.set_state(Gst.State.PLAYING)
running = True

# set_window_title('img_tensor', 'NNStreamer Face Detection Example')

# run main loop
# loop.run()

bus = pipeline.get_bus()
msg = bus.timed_pop_filtered(
    Gst.CLOCK_TIME_NONE,
    Gst.MessageType.ERROR | Gst.MessageType.EOS
)


# quit when received eos or error message
running = False
pipeline.set_state(Gst.State.NULL)
