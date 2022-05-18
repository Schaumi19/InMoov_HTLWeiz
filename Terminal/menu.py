# -- Global imports -- #


import os
import serial
import time
import sys
import ports
import glob
import threading
import multiprocessing

from menus.games import games
from menus.monitoring import monitoring
from menus.steering import steering
from menus.gestures import gestures
from menus.voice_lines import voice_lines



# -- Global variables -- #


serial_arr = []
baudrate = 0



# -- Global script -- #


def main_menu(serial_arr_param, baudrate_param):
    """This is the main menu of the InMoov terminal
    """
    global serial_arr
    serial_arr = serial_arr_param
    global baudrate
    baudrate = baudrate_param

    while True:
        choice = main_choice()

        if choice == 1:
            monitoring(serial_arr)
        elif choice == 2:
            steering(serial_arr)
        elif choice == 3:
            gestures(serial_arr)
        elif choice == 4:
            voice_lines()
        elif choice == 5:
            follow_me(serial_arr)
        elif choice == 6:
            games()


def main_choice():
    choice = 0
    while choice != 1 and choice != 2 and choice != 3 and choice != 4:
    
        os.system("clear")
        print("\nWhich action would you like to perform?\n\n")
        print("1: monitoring of servo values")
        print("2: steering of servos")
        print("3: show a gesture")
        print("4: voice lines (coming soon)")
        print("5: follow me\n")

        try:
            choice = int(input())
        except ValueError:
            pass
        
    return choice
