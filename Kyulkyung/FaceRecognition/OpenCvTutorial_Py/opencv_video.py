import numpy as np
import cv2 as cv
cap = cv.VideoCapture('pikaboo.mp4')
face_cascade = cv.CascadeClassifier('C:\opencv\sources\data\lbpcascades\lbpcascade_frontalface_improved.xml')

while(cap.isOpened()):
    ret, img = cap.read()
    gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, 1.3, 5)
    for (x, y, w, h) in faces:
        cv.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 1)
        roi_gray = gray[y:y + h, x:x + w]
        roi_color = img[y:y + h, x:x + w]

    # gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
    cv.imshow('frame',img)
    if cv.waitKey(1) & 0xFF == ord('q'):
        break
cap.release()
cv.destroyAllWindows()