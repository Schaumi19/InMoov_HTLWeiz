
import socket
import gestures as gest
import random as rand
import time
import os
import ports


def game(serial_arr):

    SERVER_ADDRESS = '127.0.0.1'
    SERVER_PORT = 22222

    c = socket.socket()
    c.connect((SERVER_ADDRESS, SERVER_PORT))
    print("Connected to " + str((SERVER_ADDRESS, SERVER_PORT)))

    c.send(bytes(" ", 'ascii'))
    while(c.recv(1).decode() != '3'):
        c.send(bytes(" ", 'ascii'))
        time.sleep(.01)

    serial_arr = ports.sort_ports(ports.setup_ports(115200))

    print("Program started")

    gestures = gest.Gestures(serial_arr)

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


def rps(num):
  if num == 0: return 'PAPER'
  elif num == 1: return 'ROCK'
  elif num == 2: return 'SCISSOR'
  else: return 'ThumbsUp'


def main():
    game([])


if __name__ == '__main__':
    main()
