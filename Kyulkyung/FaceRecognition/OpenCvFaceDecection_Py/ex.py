# def aaaa()
import cv2 as cv
import numpy as np

video_name = 'pikaboo.mp4'
m_video_capture = cv.VideoCapture(video_name)
TOTAL_FRAME = m_video_capture.get(cv.CAP_PROP_POS_FRAMES)
m_video_capture.read()
print(TOTAL_FRAME)