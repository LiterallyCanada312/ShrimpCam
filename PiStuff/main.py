import pyserial
import numpy as np
import cv2 as cv

camIndex = 0 # tbd, dont have camera yet
cap = cv.VideoCapture(camindex)
if not cap.isOpened():
    print("Camera buggin")
    exit()

while True:
    ret, frame = cap.read()
    hsv_frame =  cv.cvtColor(frame, cv.COLOR_BGR2HSV)
       