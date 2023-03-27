import cv2

face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

video = cv2.VideoCapture(0)

while True:
    check, frame = video.read()
    grey = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(grey, scaleFactor=1.1, minNeighbors=5)
    for x,y,w,h in faces:
        color = (255, 0, 0) #BGR 0-255
        stroke = 3
        width = x + w
        height = y + h
        frame = cv2.rectangle(grey, (x,y), (width, height),color, stroke)

    cv2.imshow('Face Detector', frame)

    key = cv2.waitKey(1)

    if key == 27:
        break

video.release()
cv2.destroyAllWindows()