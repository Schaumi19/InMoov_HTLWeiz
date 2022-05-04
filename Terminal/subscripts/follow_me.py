import os
import socket
import getch
import threading
import multiprocessing
import ports
import skeletonData



baudrate = 115200

serial_arr = []
dist = 0
angle = 0



def follow_me(serial_arr_param):

    global dist
    global angle

    global serial_arr
    serial_arr = serial_arr_param
    os.system("clear")

    quit = multiprocessing.Process(target=check_quit)
    quit.start()

    data_tracking = threading.Thread(target=skeletonData.Skeletondata)
    data_tracking.start()

    while quit.is_alive():
        if dist > 200:
            print("Going forward!")
            try:
                geradeaus()
            except AttributeError:
                pass
        if dist < 150:
            print("Backing off!")
            try:
                backoff()
            except AttributeError:
                pass
        else:
            print("Turning")
            try:
                drehen()
            except AttributeError:
                pass

    

def drehen():
    if not (angle > -25 and angle < 25):
        if angle > 0:
            serial_arr[0].write(bytes(";", "utf 8"))
            serial_arr[0].write(bytes(250, "utf 8"))
            serial_arr[0].write(bytes(",", "utf 8"))
            serial_arr[0].write(bytes(-250, "utf 8"))
        elif angle < 0:
            serial_arr[0].write(bytes(";", "utf 8"))
            serial_arr[0].write(bytes(-250, "utf 8"))
            serial_arr[0].write(bytes(",", "utf 8"))
            serial_arr[0].write(bytes(250, "utf 8"))
    else:
        serial_arr[0].write(bytes(";", "utf 8"))
        serial_arr[0].write(bytes(0, "utf 8"))
        serial_arr[0].write(bytes(",", "utf 8"))
        serial_arr[0].write(bytes(0, "utf 8"))


def geradeaus():
    if not (angle > -25 and angle < 25):
        if angle > 0:
            serial_arr[0].write(bytes(";", "utf 8"))
            serial_arr[0].write(bytes(425, "utf 8"))
            serial_arr[0].write(bytes(",", "utf 8"))
            serial_arr[0].write(bytes(375, "utf 8"))
        elif angle < 0:
            serial_arr[0].write(bytes(";", "utf 8"))
            serial_arr[0].write(bytes(375, "utf 8"))
            serial_arr[0].write(bytes(",", "utf 8"))
            serial_arr[0].write(bytes(425, "utf 8"))
    else:
        serial_arr[0].write(bytes(";", "utf 8"))
        serial_arr[0].write(bytes(400, "utf 8"))
        serial_arr[0].write(bytes(",", "utf 8"))
        serial_arr[0].write(bytes(400, "utf 8"))


def backoff():
    if not (angle > -25 and angle < 25):
        if angle > 0:
            serial_arr[0].write(bytes(";", "utf 8"))
            serial_arr[0].write(bytes(-425, "utf 8"))
            serial_arr[0].write(bytes(",", "utf 8"))
            serial_arr[0].write(bytes(-375, "utf 8"))
        elif angle < 0:
            serial_arr[0].write(bytes(";", "utf 8"))
            serial_arr[0].write(bytes(-375, "utf 8"))
            serial_arr[0].write(bytes(",", "utf 8"))
            serial_arr[0].write(bytes(-425, "utf 8"))
    else:
        serial_arr[0].write(bytes(";", "utf 8"))
        serial_arr[0].write(bytes(-400, "utf 8"))
        serial_arr[0].write(bytes(",", "utf 8"))
        serial_arr[0].write(bytes(-400, "utf 8"))



def check_quit():
    getch.getch()



if __name__ == '__main__':
    follow_me(ports.sort_ports(ports.setup_ports(baudrate)))
