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

