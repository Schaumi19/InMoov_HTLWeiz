import os
import cv2
from cv2 import imshow
        
#$ for d in /dev/video* ; do echo $d ; v4l2-ctl --device=$d -D --list-formats  ; echo '===============' ; done

if os.name == 'posix':
    print("Gebe den zu testenden Kameraindex an")
    x= input()
    cap = cv2.VideoCapture("/dev/video{}".format(int(x))) or 0
    print("Zum beenden ESC oder im Terminal Strg + c")
    while cap.isOpened:
        success, frame = cap.read()
        if not success:
            print("Index nicht valid")
            break
        cv2.imshow("Image", frame)
        key = cv2.waitKey(1)

        if key == 27:
            break 

if os.name == 'nt':
    print("Gebe den zu testenden Kameraindex an")
    x = input()
    cap = cv2.VideoCapture(int(x))
    print("Zum beenden ESC oder im Terminal Strg + c")

    while cap.isOpened:
        success, frame = cap.read()
        if not success:
            print("Index nicht valid")
            break
        
        cv2.imshow("Image", frame)
        key = cv2.waitKey(1)

        if key == 27:
            break     
       