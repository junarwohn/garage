import cv2 as cv
import numpy as np

img = cv.imread("cv_icon.jpg")
shrink = cv.resize(img, None, fx=0.5, fy=0.5, interpolation=cv.INTER_AREA)
cv.imshow('Original', img)
cv.imshow('Shrink', shrink)
cv.waitKey(0)
cv.destroyAllWindows()
