# -*- coding:utf-8 -*-

'''
#@Author: Magician
#@Date: 2020-07-28 10:34:17 
#@Description: Fitting the car line by  

Copyright 2020 by Magician
'''

import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np
import cv2
import math
## %%  matplotlib inline
 

image = cv2.imread('1.jpg')
 
print('This image is:', type(image), 'with dimensions:', image.shape)
