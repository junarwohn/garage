#!/usr/bin/python
import cv2
import cairo

pikachu = 'Pikachu.jpg'
power_plant = 'powerplant.jpg'

pikachu_im = cv2.imread(pikachu)
power_plant_im = cv2.imread(power_plant)

surface = cairo.ImageSurface(cairo.FORMAT_RGB24, 200, 200)

source = cairo.ImageSurface(cairo.FORMAT_RGB24, 200, 200)

mask = cairo.ImageSurface(cairo.FORMAT_A1, 200, 200)

# create mask
cr = cairo.Context(mask)
cr.set_operator(cairo.OPERATOR_SOURCE)

cr.set_source_rgba(0,0,0,1)
cr.paint()

cr.set_source_rgba(0,0,0,0)
cr.move_to(90,90)
cr.line_to(110,90)
cr.line_to(110,110)
cr.line_to(90,110)
cr.line_to(90,90)
cr.fill()

mask.write_to_png("mask.png")
