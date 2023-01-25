import numpy as np
import cv2
import tensorflow as tf

import time

tf.config.experimental.set_visible_devices([], 'GPU')
print(tf.config.get_visible_devices())


interpreter = tf.lite.Interpreter("./unet.tflite")
interpreter.allocate_tensors()
input_details = interpreter.get_input_details()
output_details = interpreter.get_output_details()

height = input_details[0]['shape'][1]
width = input_details[0]['shape'][2]
#img = Image.open(args.image).resize((width, height))

# add N dim
#input_data = np.expand_dims(img, axis=0)

#if floating_model:
#input_dat  = (np.float32(input_data) - args.input_mean) / args.input_std

#interpreter.set_tensor(input_details[0]['index'], input_data)

s_time = time.time()
cap = cv2.VideoCapture("./j_scan.mp4")
fps = cap.get(cv2.CAP_PROP_FPS)
print("fps of vid:", fps)
g_cnt = 0
while (cap.isOpened()):
    ret, frame = cap.read()
    try:
        frame = cv2.resize(frame[490:1800, 900:2850], (512,512))
    except:
        print(frame, ret)
        break
    
    img = cv2.resize(frame, (height, width))
    input_data = np.expand_dims(img, axis=0).astype(np.float32) / 255
    interpreter.set_tensor(input_details[0]['index'], input_data)
    interpreter.invoke()
    output_data = interpreter.get_tensor(output_details[0]['index'])

    th = cv2.resize(cv2.threshold(np.squeeze(output_data), 0.9, 1, cv2.THRESH_BINARY)[-1], (512,512))
    #print(frame.shape)
    img_in_rgb = frame
    #img_in_rgb = cv2.cvtColor(frame, cv2.COLOR_GRAY2RGB)

    img_in_rgb[th == 1] = [0, 0, 255]

    #cv2.imshow("result", img_in_rgb)
    if ret:
        cv2.imshow("asda", img_in_rgb)
        
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    else:
        break
    g_cnt += 1
time_delta = time.time() - s_time
print("time :", time_delta)
print("fps :", g_cnt / time_delta)
print(g_cnt)
cap.release()
cv2.destroyAllWindows()
