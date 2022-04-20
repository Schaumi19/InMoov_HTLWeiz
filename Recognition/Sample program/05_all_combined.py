# import the necessary packages
from collections import deque
from imutils.video import VideoStream
import numpy as np
import argparse
import cv2
import imutils
import time
import pyrealsense2 as rs

# construct the argument parse and parse the arguments
ap = argparse.ArgumentParser()
ap.add_argument("-v", "--video",
	help="path to the (optional) video file")
ap.add_argument("-b", "--buffer", type=int, default=64,
	help="max buffer size")
args = vars(ap.parse_args())

# define the lower and upper boundaries of the "green"
# ball in the HSV color space, then initialize the
# list of tracked points
greenLower = (29, 86, 6)
greenUpper = (64, 255, 255)
lower_blue = (110,50,50)
upper_blue = (130,255,255)
pts = deque(maxlen=args["buffer"])

#get the video from a camera
cap = cv2.VideoCapture(2)
# allow the camera or video file to warm up
time.sleep(2.0)


while(True):
    ret, frame = cap.read()
    frame = cv2.medianBlur(frame,5)
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

### resize the frame, blur it, and convert it to the HSV
	# color space
    #frame = imutils.resize(frame, width=600)
    blurred = cv2.GaussianBlur(frame, (11, 11), 0)
    hsv = cv2.cvtColor(blurred, cv2.COLOR_BGR2HSV)

    # construct a mask for the color "green", then perform
	# a series of dilations and erosions to remove any small
	# blobs left in the mask
    mask = cv2.inRange(hsv, greenLower, greenUpper)
    mask = cv2.erode(mask, None, iterations=2)
    mask = cv2.dilate(mask, None, iterations=2)

    # find contours in the mask and initialize the current
    # (x, y) center of the ball
    cnts = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL,
        cv2.CHAIN_APPROX_SIMPLE)
    cnts = imutils.grab_contours(cnts)
    center = None

# only proceed if at least one contour was found
    """if len(cnts) > 0:
        # find the largest contour in the mask, then use
        # it to compute the minimum enclosing circle and
        # centroid
        c = max(cnts, key=cv2.contourArea)
        ((x, y), radius) = cv2.minEnclosingCircle(c)
        M = cv2.moments(c)
        center = (int(M["m10"] / M["m00"]), int(M["m01"] / M["m00"]))
        # only proceed if the radius meets a minimum size
        if radius > 10:
            #draw the circle and centroid on the frame,
            #then update the list of tracked points
            cv2.circle(frame, (int(x), int(y)), int(radius),
                (0, 255, 255), 2)
            cv2.circle(frame, center, 5, (0, 0, 255), -1)"""
    # update the points queue
    pts.appendleft(center)

    # loop over the set of tracked points
    for i in range(1, len(pts)):
        # if either of the tracked points are None, ignore
        # them
        if pts[i - 1] is None or pts[i] is None:
            continue
        # otherwise, compute the thickness of the line and
        # draw the connecting lines
        thickness = int(np.sqrt(args["buffer"] / float(i + 1)) * 2.5)
        cv2.line(frame, pts[i - 1], pts[i], (0, 0, 255), thickness)
###
	# load the image, clone it for output, and then convert it to grayscale
    output = frame.copy()

	# apply GuassianBlur to reduce noise. medianBlur is also added for smoothening, reducing noise.
    gray = cv2.GaussianBlur(gray,(5,5),0)
    gray = cv2.medianBlur(gray,5)

	# Adaptive Guassian Threshold is to detect sharp edges in the Image. For more information Google it.
    gray = cv2.adaptiveThreshold(gray,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C,\
            cv2.THRESH_BINARY,11,3.5)
	
    kernel = np.ones((3,3),np.uint8)
    gray = cv2.erode(gray,kernel,iterations = 1)
	# gray = erosion
	
    gray = cv2.dilate(gray,kernel,iterations = 1)

###
	# detect circles in the image 
    #circles = cv2.HoughCircles(gray, cv2.HOUGH_GRADIENT, 1, 200, param1=30, param2=45, minRadius=0, maxRadius=0)
    circles = cv2.HoughCircles(gray, cv2.HOUGH_GRADIENT, 1, 500, param1=40, param2=30, minRadius=0, maxRadius=0)
###
#HughCircles Detection TEST  

   # circles = np.uint16(np.around(circles))
    if circles is not None :
        circles = np.round(circles[0, :]).astype("int")
        for (x, y, r) in circles:
        # draw the outer circle
            #if cv2.inRange(hsv, greenLower, greenUpper)is True:
            cv2.circle(output, (x, y), r, (0, 255, 0), 4)
            #cv2.rectangle(output, (x - 5, y - 5), (x + 5, y + 5), (0, 128, 255), -1)
#    
###

# Display the resulting frame
#
    cv2.imshow('gray',gray)
    cv2.imshow('frame',output)

    key = cv2.waitKey(1)
    if key == 27:
        break