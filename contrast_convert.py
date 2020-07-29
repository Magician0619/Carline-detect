import cv2
import numpy as np

def log(c, img):
    output_img = c*np.log(1.0+img)
    output_img = np.uint8(output_img+0.5)
    return output_img

def gamma(img, c, v):
    lut = np.zeros(256, dtype=np.float32)
    for i in range(256):
        lut[i] = c * i ** v
    output_img = cv2.LUT(img, lut)
    output_img = np.uint8(output_img+0.5)  # 这句一定要加上
    return output_img
	


img = cv2.imread('549.jpg')
cv2.imshow("input",img)

out1 = gamma(img,0.00000005,4.0)
cv2.imshow('output1', out1)

out2 = log(20,img)
cv2.imshow('output2', out2)
 
cv2.waitKey(0)#保持图像


'''
img = cv2.imread('F:\python\work\cv_learn\gamma.png',1)
 
cv2.imshow('imput', img)
def gamma(img, c, v):
    lut = np.zeros(256, dtype=np.float32)
    for i in range(256):
        lut[i] = c * i ** v
    output_img = cv2.LUT(img, lut)
    output_img = np.uint8(output_img+0.5)  # 这句一定要加上
    return output_img
 
out2 = gamma(img,0.00000005,4.0)
cv2.imshow('output', out2)
 
cv2.waitKey(0)#保持图像
'''