
import os
import time
import random
import serial


serial_arr = []


def gestures(serial_arr_param):
    global serial_arr
    serial_arr = serial_arr_param

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

        try:
            gestures.__getattribute__(choice)()
        except AttributeError:
            print("\nNot all neccesary actuators connected")
            print("continuing in: ")
            for x in range(3, 0, -1):
                print(x)
                time.sleep(1)



class Gestures():

	def __init__(self, serial_arr_param):
		global serial_arr	
		serial_arr = serial_arr_param

	def __set_default__(self, serial_index):
		self.__write_serial__(0, 70, serial_index)

	def __write_serial__(self, servo_num, value, serial_index):
		try:
			try:
				try:
				    serial_arr[serial_index].write(bytes(";" , 'ascii'))
				    serial_arr[serial_index].write(bytes(str(servo_num) , 'ascii'))
				    serial_arr[serial_index].write(bytes("," , 'ascii'))
				    serial_arr[serial_index].write(bytes(str(value) , 'ascii'))
				    serial_arr[serial_index].write(bytes(" " , 'ascii'))
				except AttributeError:
				    pass
			except serial.SerialException:
				pass
		except TypeError:
			pass


    # -- Please declare your gestures here as a function -- #

    # Rock Paper Scissors
	def rock(self):
		for x in range(2, 7):
			self.__write_serial__(x, 180, 2)

	def paper(self):
		for x in range(2, 7):
			self.__write_serial__(x, 0, 2)

	def siccors(self):
		self.paper()
		time.sleep(.25)
		self.__write_serial__(2, 180, 2)
		self.__write_serial__(5, 180, 2)
		self.__write_serial__(6, 180, 2)

	def raise_hand(self, serial_index):
		self.__write_serial__(2, 100, serial_index)
		self.__write_serial__(4, 0, serial_index)
    
	def lower_hand(self, serial_index):
		self.__write_serial__(2, 70, serial_index)
		self.__write_serial__(4, 90, serial_index)

	def rps(self, gesture):
		self.__write_serial__(4, 75, 7)
		self.__write_serial__(2, 70, 7)
		self.lower_hand(3)
		self.__write_serial__(3, 120, 3)
		self.__write_serial__(1, 0, 2)
		self.__write_serial__(2, 50, 2)
		self.__write_serial__(3, 100, 2)
		time.sleep(1)
		self.rock()
		for x in range(3):
			time.sleep(1)
			self.raise_hand(3)
			time.sleep(1)
			self.lower_hand(3)

        # only if used with serial terminal without actual game
        # gesture = random.randrange(0, 3)

		if gesture == 0:
			self.paper()
		elif gesture == 1:
			self.rock()
		elif gesture == 2:
			self.siccors()

	def shake_head(self):
		self.__write_serial__(1, 0, 4)
		time.sleep(.75)
		for x in range(3):
			self.__write_serial__(4, 0, 4)
			time.sleep(.75)
			self.__write_serial__(4, 180, 4)
			time.sleep(.75)
		self.__write_serial__(4, 90, 4)
		time.sleep(.75)
		self.__write_serial__(1, 70, 4)
		time.sleep(.75)

	def win(self):
		for x in range(2):		
			self.__write_serial__(2, 180, 7)
			self.__write_serial__(1, 90, 4)
			time.sleep(.75)
			self.__write_serial__(4, 180, 7)
			self.__write_serial__(1, 180, 4)
			time.sleep(.75)
			self.__write_serial__(4, 60, 7)
			self.__write_serial__(1, 0, 4)
			time.sleep(.75)
			self.__write_serial__(4, 180, 7)
			self.__write_serial__(1, 180, 4)
			time.sleep(.75)
		self.__write_serial__(4, 60, 7)
		self.__write_serial__(1, 70, 4)
		time.sleep(.75)
		self.__write_serial__(4, 75, 7)
		self.__write_serial__(2, 70, 7)
		time.sleep(1.5)

	def lose(self):
		self.__write_serial__(1, 10, 5)
		self.shake_head()
		self.__write_serial__(1, 110, 5)
    
    # Get keys and give keys
	def forward_left_arm(self):
		self.__write_serial__(0, 0, 2)
		self.__write_serial__(1, 180, 2)
		self.__write_serial__(4, 140, 3)
		self.__write_serial__(2, 140, 3)
    
	def backward_left_arm(self):
		self.__write_serial__(0, 180, 2)
		self.__write_serial__(1, 180, 2)
		self.__write_serial__(4, 90, 3)
		self.__write_serial__(2, 90, 3)

	def standard(self):
	    self.__write_serial__(0, 70, 3)
	    self.__write_serial__(0, 70, 7)
	    self.__write_serial__(3, 110, 7)
	    self.__write_serial__(1, 120, 5)
	    self.__write_serial__(2, 90, 5)
	    self.__write_serial__(0, 90, 4)
	    self.__write_serial__(4, 120, 4)
	    time.sleep(.5)

    # Technical demo (Europe)
	def demo(self):
		for x in range(1, 4):
			if x == 3:
				x += 1		
			self.__write_serial__(4, 170, x)
			time.sleep(.5)
			self.__write_serial__(4, 90, x)
			time.sleep(.5)
		for x in range(2, 7, 4):
			self.__write_serial__(2, 0, x)
			time.sleep(.2)
			self.__write_serial__(3, 0, x)     
			time.sleep(.2)     
			self.__write_serial__(4, 0, x)     
			time.sleep(.2)    
			self.__write_serial__(5, 0, x)     
			time.sleep(.2)
			self.__write_serial__(6, 0, x)     
			time.sleep(.2)     

			self.__write_serial__(2, 180, x)     
			time.sleep(.2)            
			self.__write_serial__(3, 180, x)     
			time.sleep(.2)     
			self.__write_serial__(4, 180, x)     
			time.sleep(.2)     
			self.__write_serial__(5, 180, x)     
			time.sleep(.2)     
			self.__write_serial__(6, 180, x)     
			time.sleep(.5)     

		self.__write_serial__(0, 40, 3)
		self.__write_serial__(0, 40, 7)
		time.sleep(.5)
		self.__write_serial__(0, 160, 3)
		self.__write_serial__(0, 160, 7)
		time.sleep(.5)

		self.__write_serial__(0, 30, 5)
		time.sleep(.5)
		self.__write_serial__(0, 150, 5)
		time.sleep(.5)
		self.__write_serial__(1, 120, 5)
		self.__write_serial__(2, 90, 5)
		time.sleep(2)
		self.standard()

		self.__write_serial__(0, 700, 0)
		time.sleep(1)
		self.__write_serial__(700, 0, 0)
		time.sleep(1)
		self.__write_serial__(-600, -600, 0)
		time.sleep(1)
