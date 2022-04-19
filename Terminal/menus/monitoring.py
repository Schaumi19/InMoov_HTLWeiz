
import getch
import multiprocessing
import threading
import os
import time


serial_arr = []


# Monitoring

left_hand = [None for x in range(5)]
left_act = [None for x in range(3)]
head = [None for x in range(6)]
middle_act = [None for x in range(2)]
right_hand = [None for x in range(5)]
right_act = [None for x in range(3)]


def monitoring(serial_arr_param):
    global serial_arr
    serial_arr = serial_arr_param

    # Start a new child process for checking if the user has pressed a key
    quit = multiprocessing.Process(target=check_quit)
    quit.start()

    # Start a new thread for reading in values from the arduinos
    read = threading.Thread(target=read_values, daemon=True)
    read.start()

    # Loop that runs while the child process is alive (The user hasn't pressed a key)
    while quit.is_alive():
        os.system("clear")

        # Print out all of the values

        try:
            print("\nLeft Hand:       " + str(left_hand[0]) + " " + str(left_hand[1]) + " " + str(left_hand[2]) + " " + str(left_hand[3]) + " " + str(left_hand[4]))
        except TypeError:
            print("\nLeft Hand:       not connected")

        try:
            print("\nLeft Actuator:   " + str(left_act[0]) + " " + str(left_act[1]) + " " + str(left_act[2]))
        except TypeError:
            print("\nLeft Actuator:   not connected")

        try:
            print("\nHead:            " + str(head[0]) + " " + str(head[1]) + " " + str(head[2]) + " " + str(head[3]) + " " + str(head[4]) + " " + str(head[5]))
        except TypeError:
            print("\nHead:            not connected")

        try:
            print("\nMiddle Actuator: " + str(middle_act[0]) + " " + str(middle_act[1]))
        except TypeError:
            print("\nMiddle Actuator: not connected")

        try:
            print("\nRight Hand:      " + str(right_hand[0]) + " " + str(right_hand[1]) + " " + str(right_hand[2]) + " " + str(right_hand[3]) + " " + str(right_hand[4]))
        except TypeError:
            print("\nRight Hand:      not connected")

        try:
            print("\nRight Actuator:  " + str(right_act[0]) + " " + str(right_act[1]) + " " + str(right_act[2]))
        except TypeError:
            print("\nRight Actuator:  not connected")
        
        time.sleep(1)


def read_values():
    """This function is used to read in the values from the different arduinos
       in a different Thread
    """
    global left_hand
    global left_act
    global head
    global middle_act
    global right_hand
    global right_act

    while True:
        try:
            try:
                try:
                    serial_arr[2].read_until(";".encode("utf-8"))
                    time.sleep(.05)
                    left_hand[0] = ord(serial_arr[2].read().decode('utf-8'))
                    left_hand[1] = ord(serial_arr[2].read().decode('utf-8'))
                    left_hand[2] = ord(serial_arr[2].read().decode('utf-8'))
                    left_hand[3] = ord(serial_arr[2].read().decode('utf-8'))
                    left_hand[4] = ord(serial_arr[2].read().decode('utf-8'))
                except serial.SerialException:
                    raise TypeError
            except AttributeError:
                raise TypeError
        except TypeError:
            left_hand = [None for x in range(5)]

        try:
            try:
                try:
                    serial_arr[3].read_until(";".encode("utf-8"))
                    time.sleep(.05)
                    left_act[0] = ord(serial_arr[3].read().decode('utf-8'))
                    left_act[1] = ord(serial_arr[3].read().decode('utf-8'))
                    left_act[2] = ord(serial_arr[3].read().decode('utf-8'))
                except serial.SerialException:
                    raise TypeError
            except AttributeError:
                raise TypeError
        except TypeError:
            left_act = [None for x in range(3)]
        
        try:
            try:
                try:
                    serial_arr[4].read_until(";".encode("utf-8"))
                    time.sleep(.05)
                    head[0] = ord(serial_arr[4].read().decode('utf-8'))
                    head[1] = ord(serial_arr[4].read().decode('utf-8'))
                    head[2] = ord(serial_arr[4].read().decode('utf-8'))
                    head[3] = ord(serial_arr[4].read().decode('utf-8'))
                    head[4] = ord(serial_arr[4].read().decode('utf-8'))
                    head[5] = ord(serial_arr[4].read().decode('utf-8'))
                except serial.SerialException:
                    raise TypeError
            except AttributeError:
                raise TypeError
        except TypeError:
            head = [None for x in range(6)]

        try:
            try:
                try:
                    serial_arr[5].read_until(";".encode("utf-8"))
                    time.sleep(.05)
                    middle_act[0] = ord(serial_arr[5].read().decode('utf-8'))
                    middle_act[1] = ord(serial_arr[5].read().decode('utf-8'))
                    middle_act[2] = ord(serial_arr[5].read().decode('utf-8'))
                    middle_act[3] = ord(serial_arr[5].read().decode('utf-8'))
                except serial.SerialException:
                    raise TypeError
            except AttributeError:
                raise TypeError
        except TypeError:
            middle_act = [None for x in range(4)]

        try:        
            try:
                try:
                    serial_arr[6].read_until(";".encode("utf-8"))
                    time.sleep(.05)
                    right_hand[0] = ord(serial_arr[6].read().decode('utf-8'))
                    right_hand[1] = ord(serial_arr[6].read().decode('utf-8'))
                    right_hand[2] = ord(serial_arr[6].read().decode('utf-8'))
                    right_hand[3] = ord(serial_arr[6].read().decode('utf-8'))
                    right_hand[4] = ord(serial_arr[6].read().decode('utf-8'))
                except serial.SerialException:
                    raise TypeError
            except AttributeError:
                raise TypeError
        except TypeError:
            right_hand = [None for x in range(5)]
            
        try:
            try:
                try:
                    serial_arr[7].read_until(";".encode("utf-8"))
                    time.sleep(.05)
                    right_act[0] = ord(serial_arr[7].read().decode('utf-8'))
                    right_act[1] = ord(serial_arr[7].read().decode('utf-8'))
                    right_act[2] = ord(serial_arr[7].read().decode('utf-8'))
                except serial.SerialException:
                    raise TypeError
            except AttributeError:
                raise TypeError
        except TypeError:
            right_act = [None for x in range(3)]



def check_quit():
    getch.getch()
