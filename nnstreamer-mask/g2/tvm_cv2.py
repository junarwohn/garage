import tvm
import tvm.relay as relay
import tensorflow as tf
import numpy as np
import cv2
import time

#tf.config.experimental.set_visible_devices([], 'GPU')
#print("visible_device", tf.config.get_visible_devices())

lib = tvm.runtime.load_module("./unet_tvm_cpu_512.so")
target = "llvm"
dev = tvm.cpu()
model = tvm.contrib.graph_runtime.GraphModule(lib['default'](dev))


#model = tf.keras.models.load_model('./face_unet.pb')
#model = tf.keras.models.load_model('./unet_256_keras.h5')
#interpreter = tf.lite.Interpreter("./face_unet.tflite")
#interpreter.allocate_tensors()
#input_details = interpreter.get_input_details()
#output_details = interpreter.get_output_details()

#height = 512 
#width = 512 
height = 512 
width = 512 
#height = input_details[0]['shape'][1]
#width = input_details[0]['shape'][2]
print(height, width)
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
        #frame = cv2.resize(frame, (512,512))
    except:
        print(frame, ret)
        break
    
    data = cv2.resize(frame, (height, width)) / 255
    #print('input',data.shape)
    #input_data = tvm.nd.array(data.astype(np.float32))
    input_data = tvm.nd.array(np.transpose(data, (2,0,1)).astype(np.float32))
    model.set_input('input_1', input_data)
    model.run()
    output_data = model.get_output(0).asnumpy()
    #input_data = np.expand_dims(img, axis=0).astype(np.float32) / 255
    #output_data = model(input_data)

    #th = cv2.resize(cv2.threshold(np.squeeze(output_data), 0.99, 1, cv2.THRESH_BINARY)[-1], (512,512))
    th = cv2.resize(cv2.threshold(np.squeeze(output_data), 0.9, 1, cv2.THRESH_BINARY)[-1], (512,512))
    #th = th[:,:,0]
    #print(frame.shape)
    img_in_rgb = frame
    #img_in_rgb = cv2.cvtColor(frame, cv2.COLOR_GRAY2RGB)

    #print(th.shape, img_in_rgb.shape)
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
