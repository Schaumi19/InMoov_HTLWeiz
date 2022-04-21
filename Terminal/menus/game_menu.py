
import gestures as gest
import random as rand
import time
import os
import socket


def games(serial_arr):
    os.system("clear")

    print("What game do you want to play? (enter quit to quit)\n")
    print("1. Rock Paper Scissors")

    choice = input()
    if choice == "quit":
        return
    elif choice == "1":
        game(serial_arr)


def game(serial_arr):
    gestures = gest.Gestures(serial_arr)

    SERVER_ADDRESS = '127.0.0.1'
    SERVER_PORT = 22222

    c = socket.socket()
    c.connect((SERVER_ADDRESS, SERVER_PORT))
    print("Connected to " + str((SERVER_ADDRESS, SERVER_PORT)))

    game_count = 1
    while game_count < 6:
        os.system("clear")
        print("Game " + str(game_count) + "\n")
        final_gest = rand.randrange(0, 3)

        gestures.rps(final_gest)

        c.send(bytes(" ", 'ascii'))

        data = c.recv(1)
        data = data.decode()
        data = ord(data) - 48

        print("\nYour sign: " + rps(data))
        print("My sign: " + rps(final_gest))

        if final_gest == 0:
            if data == 0:
                gestures.lose()
                print("I lost")
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
                print("I lost")
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
                print("I lost")

        game_count += 1
        time.sleep(3)


def rps(num):
  if num == 0: return 'PAPER'
  elif num == 1: return 'ROCK'
  elif num == 2: return 'SCISSOR'
  else: return 'ThumbsUp'
