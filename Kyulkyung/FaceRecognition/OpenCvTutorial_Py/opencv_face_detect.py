import numpy as np
import cv2 as cv
face_cascade = cv.CascadeClassifier('C:\opencv\sources\data\haarcascades\haarcascade_frontalface_default.xml')
img = cv.imread('juno.jpg')
cv.imshow('img', img)

gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
try:
    faces = face_cascade.detectMultiScale(gray, 1.3, 5)
except Exception as e:
    print(e)
for (x, y, w, h) in faces:
    cv.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 20)
    roi_gray = gray[y:y + h, x:x + w]
    roi_color = img[y:y + h, x:x + w]
cv.imshow('img', img)
cv.waitKey(0)
cv.destroyAllWindows()