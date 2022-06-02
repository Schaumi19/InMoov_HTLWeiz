import os
import threading
import multiprocessing
import ports
from PyNuitrack import py_nuitrack
import cv2 
from itertools import cycle
#from importlib_metadata import PathDistribution
#from matplotlib.pyplot import get
import numpy as np
import time
import math


baudrate = 115200
goal_dist = 150
dist_deadzone = 15
angle = 0
angle_deadzone = 20
angle_sum = 0

serial_arr = []
dist = goal_dist



def follow_me(serial_arr_param):

	global dist
	global angle
	global angle_sum

	global serial_arr
	serial_arr = serial_arr_param

	os.system("clear")

	data_tracking = threading.Thread(target=Skeletondata)
	data_tracking.start()

	prev_angle = 0
	angle_count = 0
	angle_sum = 0
	while True:

		rpm1 = 400 * (dist - goal_dist)  / 50	#Dist
		if rpm1 > 800:
			rpm1 = 800
		if rpm1 < 0:
			rpm1 *= 2
		rpm2 = rpm1

		angle_mult = 0							#Angle
		if angle > 25 or angle < -25:
			angle_mult = angle * 5

		if rpm1 < 300 and rpm1 > -300:
			if angle_mult > 300:
				angle_mult = 300
		else:
			if angle_mult > 100:
				angle_mult = 100

		

		print(angle)
		print(angle_sum)
		print(angle_mult)
		if(angle_mult > 300 or angle_mult < -300):
			angle_sum += (angle_mult/400)
		angle_mult -= angle_sum
		print(angle_mult)

		rpm1 += angle_mult
		rpm2 -= angle_mult

		if rpm1 > 800:
			rpm1 = 800
		if rpm2 > 800:
			rpm2 = 800

		print(rpm1, rpm2, angle)
		print()

		serial_arr[0].write(bytes(";", "utf 8"))
		serial_arr[0].write(bytes(str(int(rpm1)), "utf 8"))
		serial_arr[0].write(bytes(",", "utf 8"))
		serial_arr[0].write(bytes(str(int(rpm2)), "utf 8"))
		serial_arr[0].write(bytes(" ", "utf 8"))



def Skeletondata():

	def draw_skeleton(image):
		point_color = (59, 164, 0)
		for skel in data.skeletons:
			for el in skel[1:]:
				x = (round(el.projection[0]), round(el.projection[1]))
				cv2.circle(image, x, 8, point_color, -1)

	global dist
	global angle
	global angle_sum

	nuitrack = py_nuitrack.Nuitrack()
	nuitrack.init()


	devices = nuitrack.get_device_list()
	for i, dev in enumerate(devices):
		dev.get_name(), dev.get_serial_number()
		if i == 0:
			dev.get_activation()
			nuitrack.set_device(dev)


	nuitrack.get_version()
	nuitrack.get_license()
	#print('Hello1')
	nuitrack.create_modules()
	#print('Hello2')

	nuitrack.run()

	modes = cycle(["depth", "color"])
	mode = next(modes)

	while 1:
		key = cv2.waitKey(1)
		nuitrack.update()
		data = nuitrack.get_skeleton()
		data_instance=nuitrack.get_instance()
		img_depth = nuitrack.get_depth_data()

		if img_depth.size:
			cv2.normalize(img_depth, img_depth, 0, 255, cv2.NORM_MINMAX)
			img_depth = np.array(cv2.cvtColor(img_depth,cv2.COLOR_GRAY2RGB), dtype=np.uint8)
			img_color = nuitrack.get_color_data()
			draw_skeleton(img_depth)
			draw_skeleton(img_color)
			
			if not data.skeletons:
				dist = goal_dist
				angle = 0
				angle_sum = 0

			for skeleton in data.skeletons:
				zdepth = round((getattr(skeleton.torso,'real')[2])/10)  #depth in cm
				z = round((getattr(skeleton.torso,'real')[2])/10)	#depth
				x = getattr(skeleton.torso,'real')[0]
				phi = round((np.arctan(x/z))*57.3)
				data = str(z)+','+str(phi)	

				dist = zdepth
				angle = phi
				
			if key == 32:
				mode = next(modes)
			if mode == "depth":
				cv2.imshow('Image', img_depth)
			if mode == "color":
				if img_color.size:
					cv2.imshow('Image', img_color)

	nuitrack.release()



if __name__ == '__main__':
    follow_me(ports.sort_ports(ports.setup_ports(baudrate)))
