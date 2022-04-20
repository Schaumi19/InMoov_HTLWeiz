import cv2 as cv2
import numpy as np

cap = cv2.VideoCapture(2)

while(True):
    ret, frame = cap.read()
    frame = cv2.medianBlur(frame,5)
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    
    #ret, frame = cap.read()?????

	# load the image, clone it for output, and then convert it to grayscale
    output = frame.copy()

    #gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)????
	
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
	# gray = dilation

	# get the size of the final image
    #img_size = gray.shape
    #print (img_size)
	
	# detect circles in the image
    #circles = cv2.HoughCircles(gray, cv2.HOUGH_GRADIENT, 1, 200, param1=30, param2=45, minRadius=0, maxRadius=0)
    circles = cv2.HoughCircles(gray, cv2.HOUGH_GRADIENT, 1, 500, param1=40, param2=30, minRadius=0, maxRadius=0)


###
#HughCircles Detection TEST  

   # circles = np.uint16(np.around(circles))
    if circles is not None:
        circles = np.round(circles[0, :]).astype("int")
        for (x, y, r) in circles:
        # draw the outer circle
            cv2.circle(output, (x, y), r, (0, 255, 0), 4)
            cv2.rectangle(output, (x - 5, y - 5), (x + 5, y + 5), (0, 128, 255), -1)
#    
###

# Display the resulting frame
#
    cv2.imshow('gray',gray)
    cv2.imshow('frame',output)

    key = cv2.waitKey(1)
    if key == 27:
        break