
import os
import time



def gestures(serial_arr):
    gestures = Gestures(serial_arr)

    while True:
        os.system("clear")
        print("Choose a gesture (enter quit to quit): \n")

        for method in dir(Gestures):
            if not method.startswith("_"):
                print(method)

        choice = input("\n")
        if choice == "quit":
            return
        
        gestures.__getattribute__(choice)()



class Gestures():
    
    def __init__(self, serial_arr):
        self.serial_arr = serial_arr


    # -- Please declare your gestures here as a function -- #
    def rock(self):
        pass

    
    def paper(self):
        pass


    def siccors(self):
        pass
