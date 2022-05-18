
import socket
import gestures as gest
import random as rand
import time
import os
import ports


def game(serial_arr):
    os.system("clear")
    print("Program started")

    gestures = gest.Gestures(serial_arr)

    SERVER_ADDRESS = '127.0.0.1'
    SERVER_PORT = 22222

    c = socket.socket()
    c.connect((SERVER_ADDRESS, SERVER_PORT))
    print("Connected to " + str((SERVER_ADDRESS, SERVER_PORT)))

    c.send(bytes(" ", 'ascii'))
    while(c.recv(1).decode() != '3'):
        c.send(bytes(" ", 'ascii'))
        time.sleep(.01)

    print("forwarding")
    gestures.forward_left_arm()

    data = 0
    while data != 3:
        c.send(bytes(" ", 'ascii'))

        data = c.recv(1)
        data = data.decode()
        data = ord(data) - 48

    print("backwarding")
    gestures.backward_left_arm()

    data = 0
    while data != 3:
        c.send(bytes(" ", 'ascii'))

        data = c.recv(1)
        data = data.decode()
        data = ord(data) - 48

    print("forwarding")
    gestures.forward_left_arm()


def main():
    game(ports.sort_ports(ports.setup_ports(115200)))


if __name__ == '__main__':
    main()
