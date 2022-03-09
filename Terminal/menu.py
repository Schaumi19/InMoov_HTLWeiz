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


serial_arr: list[serial.Serial] = []
old_ports: list[str] = []

# Monitoring

left_hand = [None for x in range(5)]
left_act = [None for x in range(3)]
head = [None for x in range(6)]
middle_act = [None for x in range(2)]
right_hand = [None for x in range(5)]
right_act = [None for x in range(3)]



# -- Global script -- #


def main_menu(serial_arr_param: list[serial.Serial], old_ports_param: list[str]):
    """This is the main menu of the InMoov terminal
    """
    global serial_arr
    serial_arr = serial_arr_param

    # Start a new thread for checking if any new arduinos got connected
    check = threading.Thread(target=check_ports, daemon=True)
    check.start()
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
            print("\nLeft Hand:       " + left_hand[0] + " " + left_hand[1] + " " + left_hand[2] + " " + left_hand[3] + " " + left_hand[4])
        except TypeError:
            print("\nLeft Hand:       not connected")

        try:
            print("\nLeft Actuator:   " + left_act[0] + " " + left_act[1] + " " + left_act[2])
        except TypeError:
            print("\nLeft Actuator:   not connected")

        try:
            print("\nHead:            " + head[0] + " " + head[1] + " " + head[2] + " " + head[3] + " " + head[4] + " " + head[5])
        except TypeError:
            print("\nHead:            not connected")

        try:
            print("\nMiddle Actuator: " + middle_act[0] + " " + middle_act[1])
        except TypeError:
            print("\nMiddle Actuator: not connected")

        try:
            print("\nRight Hand:      " + right_hand[0] + " " + right_hand[1] + " " + right_hand[2] + " " + right_hand[3] + " " + right_hand[4])
        except TypeError:
            print("\nRight Hand:      not connected")

        try:
            print("\nRight Actuator:  " + right_act[0] + " " + right_act[1] + " " + right_act[2])
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
                    serial_arr[2].read_until(",".encode("utf 8"))
                    time.sleep(.05)
                    left_hand[0] = str(int.from_bytes(serial_arr[2].read(), sys.byteorder) + int.from_bytes(serial_arr[2].read(), sys.byteorder))
                    left_hand[1] = str(int.from_bytes(serial_arr[2].read(), sys.byteorder) + int.from_bytes(serial_arr[2].read(), sys.byteorder))
                    left_hand[2] = str(int.from_bytes(serial_arr[2].read(), sys.byteorder) + int.from_bytes(serial_arr[2].read(), sys.byteorder))
                    left_hand[3] = str(int.from_bytes(serial_arr[2].read(), sys.byteorder) + int.from_bytes(serial_arr[2].read(), sys.byteorder))
                    left_hand[4] = str(int.from_bytes(serial_arr[2].read(), sys.byteorder) + int.from_bytes(serial_arr[2].read(), sys.byteorder))
                except serial.SerialException:
                    raise TypeError
            except AttributeError:
                raise TypeError
        except TypeError:
            left_hand = [None for x in range(5)]

        try:
            try:
                try:
                    serial_arr[3].read_until(",".encode("utf 8"))
                    time.sleep(.05)
                    left_act[0] = str(int.from_bytes(serial_arr[3].read(), sys.byteorder) + int.from_bytes(serial_arr[3].read(), sys.byteorder))
                    left_act[1] = str(int.from_bytes(serial_arr[3].read(), sys.byteorder) + int.from_bytes(serial_arr[3].read(), sys.byteorder))
                    left_act[2] = str(int.from_bytes(serial_arr[3].read(), sys.byteorder) + int.from_bytes(serial_arr[3].read(), sys.byteorder))
                except serial.SerialException:
                    raise TypeError
            except AttributeError:
                raise TypeError
        except TypeError:
            left_act = [None for x in range(3)]
        
        try:
            try:
                try:
                    serial_arr[4].read_until(",".encode("utf 8"))
                    time.sleep(.05)
                    head[0] = str(int.from_bytes(serial_arr[4].read(), sys.byteorder) + int.from_bytes(serial_arr[4].read(), sys.byteorder))
                    head[1] = str(int.from_bytes(serial_arr[4].read(), sys.byteorder) + int.from_bytes(serial_arr[4].read(), sys.byteorder))
                    head[2] = str(int.from_bytes(serial_arr[4].read(), sys.byteorder) + int.from_bytes(serial_arr[4].read(), sys.byteorder))
                    head[3] = str(int.from_bytes(serial_arr[4].read(), sys.byteorder) + int.from_bytes(serial_arr[4].read(), sys.byteorder))
                    head[4] = str(int.from_bytes(serial_arr[4].read(), sys.byteorder) + int.from_bytes(serial_arr[4].read(), sys.byteorder))
                    head[5] = str(int.from_bytes(serial_arr[4].read(), sys.byteorder) + int.from_bytes(serial_arr[4].read(), sys.byteorder))
                except serial.SerialException:
                    raise TypeError
            except AttributeError:
                raise TypeError
        except TypeError:
            head = [None for x in range(6)]

        try:
            try:
                try:
                    serial_arr[5].read_until(",".encode("utf 8"))
                    time.sleep(.05)
                    middle_act[0] = str(int.from_bytes(serial_arr[5].read(), sys.byteorder) + int.from_bytes(serial_arr[5].read(), sys.byteorder))
                    middle_act[1] = str(int.from_bytes(serial_arr[5].read(), sys.byteorder) + int.from_bytes(serial_arr[5].read(), sys.byteorder))
                except serial.SerialException:
                    raise TypeError
            except AttributeError:
                raise TypeError
        except TypeError:
            middle_act = [None for x in range(2)]

        try:        
            try:
                try:
                    serial_arr[6].read_until(",".encode("utf 8"))
                    time.sleep(.05)
                    right_hand[0] = str(int.from_bytes(serial_arr[6].read(), sys.byteorder) + int.from_bytes(serial_arr[6].read(), sys.byteorder))
                    right_hand[1] = str(int.from_bytes(serial_arr[6].read(), sys.byteorder) + int.from_bytes(serial_arr[6].read(), sys.byteorder))
                    right_hand[2] = str(int.from_bytes(serial_arr[6].read(), sys.byteorder) + int.from_bytes(serial_arr[6].read(), sys.byteorder))
                    right_hand[3] = str(int.from_bytes(serial_arr[6].read(), sys.byteorder) + int.from_bytes(serial_arr[6].read(), sys.byteorder))
                    right_hand[4] = str(int.from_bytes(serial_arr[6].read(), sys.byteorder) + int.from_bytes(serial_arr[6].read(), sys.byteorder))
                except serial.SerialException:
                    raise TypeError
            except AttributeError:
                raise TypeError
        except TypeError:
            right_hand = [None for x in range(5)]
            
        try:
            try:
                try:
                    serial_arr[7].read_until(",".encode("utf 8"))
                    time.sleep(.05)
                    right_act[0] = str(int.from_bytes(serial_arr[7].read(), sys.byteorder) + int.from_bytes(serial_arr[7].read(), sys.byteorder))
                    right_act[1] = str(int.from_bytes(serial_arr[7].read(), sys.byteorder) + int.from_bytes(serial_arr[7].read(), sys.byteorder))
                    right_act[2] = str(int.from_bytes(serial_arr[7].read(), sys.byteorder) + int.from_bytes(serial_arr[7].read(), sys.byteorder))
                except serial.SerialException:
                    raise TypeError
            except AttributeError:
                raise TypeError
        except TypeError:
            right_act = [None for x in range(3)]


def check_ports():
    """Constantly checks if new arduinos were connected in a different thread
    """
    global serial_arr
    global old_ports

    while True:
        new_ports = glob.glob("/dev/tty[A-Za-z]*")
        if new_ports != old_ports:
            for port in serial_arr:
                try:
                    try:
                        try:
                            try:
                                port.close()
                            except serial.SerialException:
                                pass
                        except AttributeError:
                            raise OSError
                    except TypeError:
                        raise OSError
                except OSError:
                    pass
            serial_arr = ports.sort_ports(ports.setup_ports(sys.platform, 115200))
            old_ports = new_ports



def steering():
    os.system("clear")



def gestures():
    os.system("clear")



def voice_lines():
    os.system("clear")



def check_quit():
    getch.getch()
