#!/usr/bin/env bash
IN=$1

f_name=$(echo $IN | cut --delimiter "." --fields 1)

gcc $IN -o $f_name `pkg-config --cflags --libs gstreamer-1.0`
