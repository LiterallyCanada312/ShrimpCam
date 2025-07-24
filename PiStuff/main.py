import pyserial
import numpy as np
import cv2 as cv
import ColorFilter

camIndex = 0 # tbd, dont have camera yet
cap = cv.VideoCapture(camIndex)
if not cap.isOpened():
    print("Camera buggin")
    exit()

while True:
    ret, frame = cap.read()
    edit_frame = ColorFilter.filterTargets(frame)
    
       