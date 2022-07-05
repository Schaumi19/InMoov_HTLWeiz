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
import os
from simple_pid import PID
pid = PID(5.6, 0.6, 0.85, sample_time=0.0005, setpoint=1)
pidDist = PID(5, 0.6, 1, sample_time=0.01, setpoint=1)

baudrate = 115200
goal_dist = 160
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

	angle_sum = 0
	while True:
		rpm1 = 0
		rpm2 = 0

		rpm1 = pidDist(dist-goal_dist) * -1
		if rpm1 > 800:
			rpm1 = 800
		rpm2 = rpm1

		angle_rpm = pid(angle) * -1
		#angle_rpm = 0

		"""
		if(angle_rpm > 330):
			angle_rpm = 330
		if(angle_rpm < -330):
			angle_rpm = -330
		"""
		if rpm1 < 180 and rpm1 > -180:
			rpm1 += angle_rpm
			rpm2 -= angle_rpm
		else:
			rpm1 += angle_rpm/2
			rpm2 -= angle_rpm/2
		"""
		maxI = 9
		if rpm1 > maxI:
			rpm1 = maxI
		if rpm2 > maxI:
			rpm2 = maxI
		"""

		print(rpm1, rpm2, angle, angle_rpm)
		print()

		serial_arr[0].write(bytes(";", "utf 8"))
		serial_arr[0].write(bytes(str(int(rpm1)), "utf 8"))
		serial_arr[0].write(bytes(",", "utf 8"))
		serial_arr[0].write(bytes(str(int(rpm2)), "utf 8"))
		serial_arr[0].write(bytes(" ", "utf 8"))

"""
		serial_arr[4].write(bytes(";", "utf 8"))
		serial_arr[4].write(bytes("4", "utf 8"))
		serial_arr[4].write(bytes(",", "utf 8"))
		serial_arr[4].write(bytes(str(int(np.interp(angle, [-40, 40], [150, 30]))), "utf 8"))
		serial_arr[4].write(bytes(" ", "utf 8"))
"""


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
