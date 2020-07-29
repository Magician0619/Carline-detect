import cv2 
import numpy as np

a = cv2.imread("1.jpg")
b = cv2.cvtColor(a, cv2.COLOR_BGR2HSV)

cv2.namedWindow("RGB", cv2.WINDOW_AUTOSIZE)
cv2.imshow("input",a)
cv2.namedWindow("HSV", cv2.WINDOW_AUTOSIZE)
cv2.imshow("output",b)
cv2.imwrite("1_hsv.jpg",b)


cv2.waitKey(0)
'''
if 0xFF != ord('q'):
    cv2.waitKey(1) 
cv2.destroyAllWindows()
'''