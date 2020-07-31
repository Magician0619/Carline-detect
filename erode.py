'''
from matplotlib import pyplot as pl
import numpy as np

x = np.linspace(0, 30, 30)
y = np.sin(x/6*np.pi)
error = np.random.normal(0.1, 0.02, size=y.shape)
y += np.random.normal(0, 0.1, size=y.shape)

pl.plot(x, y, 'k-')
pl.fill_between(x, y-error, y+error)
pl.show()
'''
import cv2

def erode_demo(image):
    # print(image.shape)
    # gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    # ret, binary = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)
    # cv2.imshow("binary", binary)
    binary = image
    cv2 .imshow("input",binary)
    # kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
    dst = cv2.erode(binary, cv2.getStructuringElement(cv2.MORPH_RECT, (4, 4)),iterations=1)
    cv2.imshow("erode", dst)
    cv2.imwrite("erode.jpg",dst)


image = cv2.imread("519.jpg")
erode_demo(image)

cv2.waitKey(0)