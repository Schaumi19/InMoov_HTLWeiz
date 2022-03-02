# -- Global imports -- #


import os
import serial
import time



# -- Global script -- #


def main_menu(serial_arr: list[serial.Serial]):
    """This is the main menu of the InMoov terminal
    """
    while(True):
        choice = main_choice()

        if choice == 1:
            monitoring(serial_arr)
        elif choice == 2:
            steering()
        elif choice == 3:
            gestures()
        elif choice == 4:
            voice_lines()


def main_choice():
    os.system("clear")
    print("\nWhich action would you like to perform?\n\n")
    print("1: monitoring of servo values")
    print("2: steering of servos")
    print("3: show/create a gesture (coming soon)")
    print("4: voice lines (comint soon)\n")

    choice = int(input())
    while choice != 1 and choice != 2 and choice != 3 and choice != 4:
        print("Please enter again")
        choice = int(input())
    return choice


def monitoring(serial_arr: list[serial.Serial]):
    while True:
        os.system("clear")

        try:
            serial_arr[2].read_all()
            time.sleep(.05)
            b = serial_arr[2].readline()
            c = serial_arr[2].readline()
            d = serial_arr[2].readline()
            e = serial_arr[2].readline()
            f = serial_arr[2].readline()
            print("\nLeft Hand:       " + b + " " + c + " " + d + " " + e + " " + f + "\n")
        except AttributeError:
            print("\nLeft Hand:       not connected")

        try:
            serial_arr[3].read_all()
            time.sleep(.05)
            b = serial_arr[3].readline()
            c = serial_arr[3].readline()
            d = serial_arr[3].readline()
            print("\nLeft Actuator:   " + b + " " + c + " " + d + "\n")
        except AttributeError:
            print("\nLeft Actuator:   not connected")

        try:
            serial_arr[4].read_all()
            time.sleep(.05)
            b = serial_arr[4].readline()
            c = serial_arr[4].readline()
            d = serial_arr[4].readline()
            e = serial_arr[4].readline()
            f = serial_arr[4].readline()
            print("\nHead:            " + b + " " + c + " " + d + " " + e + " " + f + "\n")
        except AttributeError:
            print("\nHead:            not connected")

        try:
            serial_arr[3].read_all()
            time.sleep(.05)
            b = serial_arr[3].readline()
            c = serial_arr[3].readline()
            print("\nMiddle Actuator: " + b + " " + c + "\n")
        except AttributeError:
            print("\nMiddle Actuator: not connected")

        try:
            serial_arr[6].read_all()
            time.sleep(.05)
            b = serial_arr[6].readline()
            c = serial_arr[6].readline()
            d = serial_arr[6].readline()
            e = serial_arr[6].readline()
            f = serial_arr[6].readline()
            print("\nRight Hand:      " + b + " " + c + " " + d + " " + e + " " + f + "\n")
        except AttributeError:
            print("\nRight Hand:      not connected")

        try:
            serial_arr[7].read_all()
            time.sleep(.05)
            b = serial_arr[7].readline()
            c = serial_arr[7].readline()
            d = serial_arr[7].readline()
            print("\nRight Actuator:  " + b + " " + c + " " + d + "\n")
        except AttributeError:
            print("\nRight Actuator:  not connected")


def steering():
    os.system("clear")


def gestures():
    os.system("clear")


def voice_lines():
    os.system("clear")


if __name__ == "__main__":
    main_menu([0 for x in range(9)])
