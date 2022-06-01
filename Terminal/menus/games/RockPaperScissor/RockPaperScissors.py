import socket
import gestures as gest
import random as rand
import time
import os
import ports
import speech_recognition as sr


def game(serial_arr):

	SERVER_ADDRESS = '127.0.0.1'
	SERVER_PORT = 22222

	c = socket.socket()
	c.connect((SERVER_ADDRESS, SERVER_PORT))
	print("Connected to " + str((SERVER_ADDRESS, SERVER_PORT)))

	keyWord = "Game"
	while True:
	    # obtain audio from the microphone
		r = sr.Recognizer()
		with sr.Microphone() as source:
			print("Listening!")
			r.adjust_for_ambient_noise(source)
			audio = r.listen(source)
			

		try:
			text = r.recognize_google(audio)
			print(text) 
			if keyWord.lower() in text.lower():
			    break
		except sr.UnknownValueError:
			print("Could not understand audio")

	serial_arr = ports.sort_ports(ports.setup_ports(115200))

	print("Game started")

	gestures = gest.Gestures(serial_arr)
#    gestures.greet_crowd()

	game_count = 1
	while game_count < 4:
		os.system("clear")
		print("Game " + str(game_count) + "\n")
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
		time.sleep(3)


	os.system("clear")
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
	time.sleep(3)

	gestures.greet_crowd()


def rps(num):
  if num == 0: return 'PAPER'
  elif num == 1: return 'ROCK'
  elif num == 2: return 'SCISSOR'
  else: return 'ThumbsUp'


def main():
    game([])


if __name__ == '__main__':
    main()
