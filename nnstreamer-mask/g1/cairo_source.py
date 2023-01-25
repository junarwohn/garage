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
import cairo
import cv2
import numpy as np

im_pen = cv2.imread('/home/parallels/paarthurnax/g1/penguin.png')
print(im_pen.shape)
source = cairo.ImageSurface.create_for_data(cairo.Format.RGB24, np.array(im_pen).astype(np.uint8), len(im_pen), len(im_pen[0]))