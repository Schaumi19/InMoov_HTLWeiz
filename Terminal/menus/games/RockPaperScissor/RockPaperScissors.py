import socket
from menus.games.RockPaperScissor import speech
from ...gestures import Gestures
import random as rand
import time
import os
#import ports
import speech_recognition as sr
import threading
#import cv2
from itertools import cycle
import numpy as np
import pyaudio
# Skeleton tracking
# from PyNuitrack import py_nuitrack
# from simple_pid import PID
# pid = PID(5, 0.85, 1.2, setpoint=1)

following = True
camera_in_use = True

goal_dist = 120
dist = goal_dist
dist_deadzone = 15
angle = 0
angle_deadzone = 20

serial_arr = []


def game(serial_port):
    gestures = Gestures(serial_port)

    # global following
    # follow = threading.Thread(target=follow_me)
    # follow.start()
    if os.name=="posix":
        os.close(sys.stderr.fileno())
    timing = threading.Thread(target=timer_func)
    timing.start()

    gestures.normal()
    keyWord = "Game"
    while timing.is_alive():
        # obtain audio from the microphone
        r = sr.Recognizer()  
        with sr.Microphone() as source:
            r.energy_threshold = 1500 
            r.dynamic_energy_threshold = True 
            r.pause_threshold = 0.8 
            print("Listening!")
            r.adjust_for_ambient_noise(source)
            audio = r.listen(source)
            try:
                text = r.recognize_google(audio,language='en-GB')
                print(text)
                if keyWord.lower() in text.lower():
                    print("Karl")
                    break
            except sr.UnknownValueError:
                print("Could not understand audio")
    # else:
    # following = False

    SERVER_ADDRESS = '127.0.0.1'
    SERVER_PORT = 22222

    c = socket.socket()
    c.connect((SERVER_ADDRESS, SERVER_PORT))
    print("Connected to " + str((SERVER_ADDRESS, SERVER_PORT)))

    print("Game started")

    gestures.nod()
    speech.speak("Yes! Let's play a game!", "en")

    game_count = 1
    while game_count < 4:
        os.system("clear")
        print("Game " + str(game_count) + "\n")
        speech.speak(f"Game {game_count} starts now!", "en")
        final_gest = rand.randrange(0, 3)

        gestures.rps(final_gest)

        c.send(bytes(" ", 'ascii'))

        data = c.recv(1)
        data = data.decode()
        data = ord(data) - 48

        time.sleep(1)

        print("\nYour sign: " + rps(data))
        print("My sign: " + rps(final_gest))

        if final_gest == 0:
            if data == 0:
                speech.speak("Oh no! Looks like we tied!", "en")
                gestures.lose()
                print("We tied")
            if data == 1:
                speech.speak("Yes, i won!", "en")
                gestures.win()
                print("I won")
            if data == 2:
                speech.speak("Oh no! Looks like i lost!", "en")
                gestures.lose()
                print("I lost")

        if final_gest == 1:
            if data == 0:
                speech.speak("Oh no! Looks like i lost!", "en")
                gestures.lose()
                print("I lost")
            if data == 1:
                speech.speak("Oh no! Looks like we tied!", "en")
                gestures.lose()
                print("We tied")
            if data == 2:
                speech.speak("Yes, i won!", "en")
                gestures.win()
                print("I won")

        if final_gest == 2:
            if data == 0:
                speech.speak("Yes, i won!", "en")
                gestures.win()
                print("I won")
            if data == 1:
                speech.speak("Oh no! Looks like i lost!", "en")
                gestures.lose()
                print("I lost")
            if data == 2:
                speech.speak("Oh no! Looks like we tied!", "en")
                gestures.lose()
                print("We tied")

        game_count += 1
        gestures.normal()
    time.sleep(3)
    
    
def rps(num):
    if num == 0:
        return 'PAPER'
    elif num == 1:
        return 'ROCK'
    elif num == 2:
        return 'SCISSOR'
    else:
        return 'ThumbsUp'

    '''os.system("clear")
    print("Game " + str(game_count) + "\n")
    final_gest = 1

    gestures.rps(final_gest)

    c.send(bytes(" ", 'ascii'))

    data = c.recv(1)
    data = data.decode()
    data = ord(data) - 48

    time.sleep(1)

    print("\nYour sign: " + rps(data))
    print("My sign: " + rps(final_gest))

    if final_gest == 0:
        if data == 0:
            gestures.lose()
            print("We tied")
        if data == 1:
            gestures.win()
            print("I won")
        if data == 2:
            gestures.lose()
            print("I lost")

    if final_gest == 1:
        if data == 0:
            gestures.lose()
            print("I lost")
        if data == 1:
            gestures.lose()
            print("We tied")
        if data == 2:
            gestures.win()
            print("I won")

    if final_gest == 2:
        if data == 0:
            gestures.win()
            print("I won")
        if data == 1:
            gestures.lose()
            print("I lost")
        if data == 2:
            gestures.lose()
            print("We tied")

    game_count += 1
    time.sleep(3)'''





'''
def follow_me():
	global dist
	global angle

	global serial_arr

	os.system("clear")

	data_tracking = threading.Thread(target=Skeletondata)
	data_tracking.start()

	while following == True:
		rpm1 = 0
		rpm2 = 0
		rpm1 = 400 * (dist - goal_dist)  / 50	#Dist
		if rpm1 > 800:
			rpm1 = 800
		rpm2 = rpm1

		angle_rpm = pid(angle) * -1
		if(angle_rpm > 330):
			angle_rpm = 330
		if(angle_rpm < -330):
			angle_rpm = -330

		if rpm1 < 180 and rpm1 > -180:
			rpm1 += angle_rpm
			rpm2 -= angle_rpm
		else:
			rpm1 += angle_rpm/3
			rpm2 -= angle_rpm/3

		if rpm1 > 800:
			rpm1 = 800
		if rpm2 > 800:
			rpm2 = 800

		print(rpm1, rpm2, angle, angle_rpm)
		print()

		serial_arr[0].write(bytes(";", "utf 8"))
		serial_arr[0].write(bytes(str(int(rpm1)), "utf 8"))
		serial_arr[0].write(bytes(",", "utf 8"))
		serial_arr[0].write(bytes(str(int(rpm2)), "utf 8"))
		serial_arr[0].write(bytes(" ", "utf 8"))

'''
'''
def Skeletondata():

	def draw_skeleton(image):
		point_color = (59, 164, 0)
		for skel in data.skeletons:
			for el in skel[1:]:
				x = (round(el.projection[0]), round(el.projection[1]))
				cv2.circle(image, x, 8, point_color, -1)

	global dist
	global angle

	nuitrack = py_nuitrack.Nuitrack()
	nuitrack.init()


	devices = nuitrack.get_device_list()
	for i, dev in enumerate(devices):
		dev.get_name(), dev.get_serial_number()
		if i == 0:
			dev.get_activation()
			nuitrack.set_device(dev)


	nuitrack.get_version()
	nuitrack.get_license()
	#print('Hello1')
	nuitrack.create_modules()
	#print('Hello2')

	nuitrack.run()

	modes = cycle(["depth", "color"])
	mode = next(modes)

	while following == True:
		key = cv2.waitKey(1)
		nuitrack.update()
		data = nuitrack.get_skeleton()
		data_instance=nuitrack.get_instance()
		img_depth = nuitrack.get_depth_data()

		if img_depth.size:
			cv2.normalize(img_depth, img_depth, 0, 255, cv2.NORM_MINMAX)
			img_depth = np.array(cv2.cvtColor(img_depth,cv2.COLOR_GRAY2RGB), dtype=np.uint8)
			img_color = nuitrack.get_color_data()
			draw_skeleton(img_depth)
			draw_skeleton(img_color)
			
			if not data.skeletons:
				dist = goal_dist
				angle = 0

			for skeleton in data.skeletons:
				zdepth = round((getattr(skeleton.torso,'real')[2])/10)  #depth in cm
				z = round((getattr(skeleton.torso,'real')[2])/10)	#depth
				x = getattr(skeleton.torso,'real')[0]
				phi = round((np.arctan(x/z))*57.3)
				data = str(z)+','+str(phi)	

				dist = zdepth
				angle = phi
				
			if key == 32:
				mode = next(modes)
			if mode == "depth":
				cv2.imshow('Image', img_depth)
			if mode == "color":
				if img_color.size:
					cv2.imshow('Image', img_color)

	nuitrack.release()
	cv2.destroyAllWindows()

	global camera_in_use
	camera_in_use = False

'''


def timer_func():
    time.sleep(50)


def main():
    game()


if __name__ == '__main__':
    main()
