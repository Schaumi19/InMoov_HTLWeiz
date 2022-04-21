
import os
import time
import random


serial_arr = []


def gestures(serial_arr_param):
    global serial_arr
    serial_arr = serial_arr_param

    gestures = Gestures()

    while True:
        os.system("clear")
        print("Choose a gesture (enter quit to quit): \n")

        for method in dir(Gestures):
            if not method.startswith("_"):
                print(method)

        choice = input("\n")
        if choice == "quit":
            return

        try:
            gestures.__getattribute__(choice)()
        except AttributeError:
            print("\nNot all neccesary actuators connected")
            print("continuing in: ")
            for x in range(3, 0, -1):
                print(x)
                time.sleep(1)



class Gestures():

    def __set_default__(self, serial_index):
        self.__write_serial__(0, 70, serial_index)

    def __write_serial__(self, servo_num, value, serial_index):
        serial_arr[serial_index].write(bytes(";" , 'ascii'))
        serial_arr[serial_index].write(bytes(str(servo_num) , 'ascii'))
        serial_arr[serial_index].write(bytes("," , 'ascii'))
        serial_arr[serial_index].write(bytes(str(value) , 'ascii'))
        serial_arr[serial_index].write(bytes(" " , 'ascii'))


    # -- Please declare your gestures here as a function -- #

    # Rock Paper Scissors
    def rock(self):
        for x in range(2, 7):
            self.__write_serial__(x, 180, 6)

    def paper(self):
        for x in range(2, 7):
            self.__write_serial__(x, 0, 6)

    def siccors(self):
        self.paper()
        time.sleep(.25)
        self.__write_serial__(2, 180, 6)
        self.__write_serial__(5, 180, 6)
        self.__write_serial__(6, 180, 6)

    def raise_hand(self):
        pass
    
    def lower_hand(self):
        pass

    def rps(self, gesture):
        self.__set_default__(6)
        time.sleep(1)
        self.rock()
        for x in range(3):
            time.sleep(.75)
            self.raise_hand()
            time.sleep(.75)
            self.lower_hand()

        if gesture == 0:
            self.rock()
        elif gesture == 1:
            self.paper()
        elif gesture == 2:
            self.siccors()
        
        time.sleep(1)
