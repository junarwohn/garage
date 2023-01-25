# https://www.pyimagesearch.com/2015/11/16/hog-detectmultiscale-parameters-explained/
# https://docs.opencv.org/3.1.0/d7/d8b/tutorial_py_face_detection.html#gsc.tab=0

import cv2 as cv
import numpy as np

# this function return detect or unable to detect ,rectangle marked image
def frame_face_recognition(img, face_cascade_):
    grayed_img = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

    # def detectMultiScale(self, image, scaleFactor=None, minNeighbors=None, flags=None, minSize=None, maxSize=None)
    faces = face_cascade_.detectMultiScale(image=grayed_img,scaleFactor=1.3,minNeighbors=5)
    for (x, y, w, h) in faces:
        cv.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 10)
        roi_gray = grayed_img[y:y + h, x:x + w]
        roi_color = img[y:y + h, x:x + w]
    is_detected = True
    if len(faces) == 0:
        is_detected = False
    return is_detected, img

# this function return frame by play_speed
def get_frame(video_capture, play_speed=1):
    curr_frame = video_capture.get(cv.CAP_PROP_POS_FRAMES)
    video_capture.set(cv.CAP_PROP_POS_FRAMES, curr_frame + play_speed)
    ret, img = video_capture.read()
    fps = video_capture.get(cv.CAP_PROP_FPS)
    return img, (curr_frame + play_speed) / fps

# this function show image and quit when press q or end
def show_img(img):
    cv.imshow('hello', img)
    if cv.waitKey(1) & 0xFF == ord('q'):
        return False
    else:
        return True

if __name__ == "__main__":
    face_cascade = cv.CascadeClassifier('C:\opencv\sources\data\lbpcascades\lbpcascade_frontalface_improved.xml')
    video_name = 'pikaboo.mp4'
    # m_video_capture = cv.VideoCapture(0)
    m_video_capture = cv.VideoCapture(video_name)
    TOTAL_FRAME = m_video_capture.get(cv.CAP_PROP_FRAME_COUNT)
    while (m_video_capture.get(cv.CAP_PROP_POS_FRAMES) < TOTAL_FRAME):
        img, sec = get_frame(video_capture=m_video_capture, play_speed=2)
        is_detected, boxed_img = frame_face_recognition(img=img, face_cascade_=face_cascade)
        if is_detected:
            print(sec)

        # keyboard interrupt (q)
        if not show_img(img):
            break
    #
    # cap = cv.VideoCapture(0)
    # while (True):
    #     # img, sec = get_frame(video_capture=m_video_capture, play_speed=10)
    #     # is_detected, boxed_img = frame_face_recognition(img=img, face_cascade_=face_cascade)
    #     # if is_detected:
    #     #     print(sec)
    #     #
    #     # # keyboard interrupt (q)
    #     # if not show_img(img):
    #     #     break
    #     # Capture frame-by-frame
    #     ret, frame = cap.read()
    #     # Our operations on the frame come here
    #     # gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
    #     # Display the resulting frame
    #     is_d, img = frame_face_recognition(frame, face_cascade)
    #     cv.imshow('frame', img)
    #     if cv.waitKey(1) & 0xFF == ord('q'):
    #         break
    # When everything done, release the capture
    # cap.release()
    # cv.destroyAllWindows()