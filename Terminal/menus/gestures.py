
import os
import time


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

    def __set_default__(self):
        serial_arr[7].write(bytes(";" , 'ascii'))
        serial_arr[7].write(bytes("0" , 'ascii'))
        serial_arr[7].write(bytes("," , 'ascii'))
        serial_arr[7].write(bytes("70" , 'ascii'))


    # -- Please declare your gestures here as a function -- #
    def rock(self):
        self.__set_default__()

    
    def paper(self):
        self.__set_default__()


    def siccors(self):
        self.__set_default__()
