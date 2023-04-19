#Programme core
model_name = 'hand_model.sav'

# custom function
def rps(num):
  if num == 0: return 'PAPER'
  elif num == 1: return 'ROCK'
  elif num == 2: return 'SCISSOR'
  else: return 'ThumbsUp'

# Import
import os
import cv2 
import hand_detection_module
from data_generate import num_hand
import pickle
import socket
from id_distance import calc_all_distance
import threading

print("Gebe den Kameraindex ein")
x = input()

if os.name == 'posix':
  cap = cv2.VideoCapture("/dev/video{}".format(int(x)))

if os.name == 'nt':
  cap = cv2.VideoCapture(int(x))
  
resdata = None
def recieve_data():
  global resdata
  while True:
    resdata = c.recv(1)

SERVER_ADDRESS = '127.0.0.1'
SERVER_PORT = 22222
s = socket.socket()
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
s.bind((SERVER_ADDRESS, SERVER_PORT))
s.listen(5)
print("Listening on address %s. Kill server with Ctrl-C" %
      str((SERVER_ADDRESS, SERVER_PORT)))
c, addr = s.accept()
print("\nConnection received from %s" % str(addr)) 


font = cv2.FONT_HERSHEY_PLAIN
hands = hand_detection_module.HandDetector(max_hands=num_hand)
model = pickle.load(open((model_name),'rb'))

recieve = threading.Thread(target=recieve_data)
recieve.start()
while cap.isOpened():
  success, frame = cap.read()
  if not success:
    print("Ignoring empty camera frame.")
    continue

  image, my_list = hands.find_hand_landmarks(cv2.flip(frame, 1),draw_landmarks=False)
  cv2.imshow("Image",frame)
  
  if my_list:
    print("Carl")
    height, width, _ = image.shape
    all_distance = calc_all_distance(height,width, my_list)
    pred = rps(model.predict([all_distance])[0])
    pos = (int(my_list[12][0]*height), int(my_list[12][1]*width))
    image = cv2.putText(image,pred,pos,font,2,(0,0,0),2)
    if pred == 'PAPER' :  state = "0"
    elif pred == 'ROCK':  state = "1"
    elif pred == 'SCISSOR': state = "2"
    #elif pred == 'ThumbsUp':  state = "3"
    data = state.encode()
    print(data)
    if resdata != None:
      resdata = None
      c.send(data)
    key = cv2.waitKey(1)

    if key == 27:
        break