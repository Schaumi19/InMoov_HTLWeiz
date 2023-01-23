import cv2
from cv2 import imshow
#$ for d in /dev/video* ; do echo $d ; v4l2-ctl --device=$d -D --list-formats  ; echo '===============' ; done
cap = cv2.VideoCapture("/dev/video4")
while cap.isOpened():
	success, frame = cap.read()
	if not success:
		print("Error")
		continue
	
	cv2.imshow("Image", frame)
	key = cv2.waitKey(1)
	
	if key == 27:
		break
