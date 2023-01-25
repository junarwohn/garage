#!/bin/bash -e
sudo rmmod i2c_hid
sudo modprobe i2c_hid
exit 0
