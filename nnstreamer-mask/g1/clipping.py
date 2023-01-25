#!/usr/bin/python

'''
ZetCode PyCairo tutorial 

This program shows how to perform
clipping in PyCairo.

author: Jan Bodnar
website: zetcode.com
'''


from gi.repository import Gtk, GLib
import cairo
import math
import random


class Example(Gtk.Window):

    def __init__(self):
        super(Example, self).__init__()
        
        self.init_ui()
        self.load_image()
        self.init_vars()
        
        
    def init_ui(self):    

        self.darea = Gtk.DrawingArea()
        self.darea.connect("draw", self.on_draw)
        self.add(self.darea)
        
        GLib.timeout_add(100, self.on_timer)

        self.set_title("Clipping")
        self.resize(300, 200)
        self.set_position(Gtk.WindowPosition.CENTER)
        self.connect("delete-event", Gtk.main_quit)
        self.show_all()
        
        
    def load_image(self):
        
        self.image = cairo.ImageSurface.create_from_png("Pikachu.png")
 
        
    def init_vars(self):    
    
        self.pos_x = 128
        self.pos_y = 128
        self.radius = 40

        self.delta = [3, 3]        
        
        
    def on_timer(self):
        
        self.pos_x += self.delta[0]
        self.pos_y += self.delta[1]        
           
        self.darea.queue_draw()
        return True           
        
    
    def on_draw(self, wid, cr):

        w, h = self.get_size()

        if (self.pos_x < 0 + self.radius):
            self.delta[0] = random.randint(5, 9)
        elif (self.pos_x > w - self.radius):
            self.delta[0] = -random.randint(5, 9)
        
        if (self.pos_y < 0 + self.radius): 
            self.delta[1] = random.randint(5, 9)
        elif (self.pos_y > h - self.radius):
            self.delta[1] = -random.randint(5, 9)        

        cr.set_source_surface(self.image, 1, 1)
        cr.arc(self.pos_x, self.pos_y, self.radius, 0, 2*math.pi)
        cr.clip()
        cr.paint()        
        
    
def main():
    
    app = Example()
    Gtk.main()
        
        
if __name__ == "__main__":    
    main()