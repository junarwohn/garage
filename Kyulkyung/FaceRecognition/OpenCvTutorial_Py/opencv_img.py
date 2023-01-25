import numpy as np
import cv2 as cv
from matplotlib import pyplot as plt

img_src = 'cv_icon.png'
img = cv.imread(img_src, 0)
cv.imshow(img_src, img)
cv.waitKey(0)
cv.destroyAllWindows()

# cv.imwrite('cv_gray.png',img)
plt.imshow(img, cmap = 'gray', interpolation = 'bicubic')
plt.xticks([]), plt.yticks([])  # to hide tick values on X and Y axis
plt.show()