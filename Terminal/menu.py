# -- Global imports -- #


import os
import serial
import time
import sys
import ports
import glob
import threading
import multiprocessing
import getch



# -- Global variables -- #


serial_arr = []
baudrate = 0

# Monitoring

left_hand = [None for x in range(5)]
left_act = [None for x in range(3)]
head = [None for x in range(6)]
middle_act = [None for x in range(2)]
right_hand = [None for x in range(5)]
right_act = [None for x in range(3)]



# -- Global script -- #


def main_menu(serial_arr_param, baudrate_param):
    """This is the main menu of the InMoov terminal
    """
    global serial_arr
    serial_arr = serial_arr_param
    global baudrate
    baudrate = baudrate_param

    # Start a new thread for reading in values from the arduinos
    read = threading.Thread(target=read_values, daemon=True)
    read.start()

    while True:
        choice = main_choice()

        if choice == 1:
            monitoring()
        elif choice == 2:
            steering()
        elif choice == 3:
            gestures()
        elif choice == 4:
            voice_lines()


def main_choice():
    choice = 0
    while choice != 1 and choice != 2 and choice != 3 and choice != 4:
    
        os.system("clear")
        print("\nWhich action would you like to perform?\n\n")
        print("1: monitoring of servo values")
        print("2: steering of servos")
        print("3: show/create a gesture (coming soon)")
        print("4: voice lines (coming soon)\n")

        try:
            choice = int(input())
        except ValueError:
            pass
        
    return choice


def monitoring():
    global serial_arr

    # Start a new child process for checking if the user has pressed a key
    quit = multiprocessing.Process(target=check_quit)
    quit.start()

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



def steering():
    global serial_arr    

    # Loop that runs while the child process is alive (The user hasn't pressed a key)
    while True:
        os.system("clear")

        print("Please enter the right combination to steer the body part: ")
        choice1 = input("Enter the side of the body (l... left, m... middle, r... right)   ")
        choice2 = input("Enter the body part (h... hand/head, a... actuator, b... board)   ")
        if choice2 != "b":
            choice3 = input("Enter the servo to steer   ")
            choice4 = input("Enter the new angle of the body part (0->180)   ")

        if choice1 == "l":
            if choice2 == "h":
                serial_arr[2].write(bytes(choice3 , 'utf-8'))
                serial_arr[2].write(bytes(choice4 , 'utf-8'))
            if choice2 == "a":
                serial_arr[3].write(bytes(choice3 , 'utf-8'))
                serial_arr[3].write(bytes(choice4 , 'utf-8'))
        
        if choice1 == "m":
            if choice2 == "h":
                serial_arr[4].write(bytes(choice3 , 'utf-8'))
                serial_arr[4].write(bytes(choice4 , 'utf-8'))
            if choice2 == "a":
                serial_arr[5].write(bytes(choice3 , 'utf-8'))
                serial_arr[5].write(bytes(choice4 , 'utf-8'))
            if choice2 == "b":
                choice4 = str()
                while choice4 != "quit":
                    os.system("clear")
                    choice4 = input("Please enter the command for the board   ")
                    new_c4 = choice4.split()
                    print("working")
                    serial_arr[0].write(bytes(";" , 'ascii'))
                    print("done1")
                    serial_arr[0].write(bytes(new_c4[0] , 'utf-8'))
                    print("done2")
                    serial_arr[0].write(bytes("," , 'ascii'))
                    print("done3")
                    serial_arr[0].write(bytes(new_c4[1] , 'utf-8'))
                    print("done4")

        if choice1 == "r":
            if choice2 == "h":
                serial_arr[6].write(bytes(choice3 , 'utf-8'))
                serial_arr[6].write(bytes(choice4 , 'utf-8'))
            if choice2 == "a":
                serial_arr[7].write(bytes(choice3 , 'utf-8'))
                serial_arr[7].write(bytes(choice4 , 'utf-8'))



def gestures():
    os.system("clear")



def voice_lines():
    os.system("clear")



def follow_me():
    os.system("clear")
    while True:
        while dist > 200:
            gradeaus()
        while dist < 150:
            backoff()
        drehen()


def drehen():
    if not (angle > -5 and angle < 5):
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
    if not (angle > -5 and angle < 5):
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
    if not (angle > -5 and angle < 5):
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
