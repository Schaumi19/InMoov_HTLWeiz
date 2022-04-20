from asyncio import sleep
from PyNuitrack import py_nuitrack
import cv2 
from itertools import cycle
from matplotlib.pyplot import get
import numpy as np
import socket

#HOST = "192.168.23.15"  # The server's hostname or IP address
#PORT = 65432  # The port used by the server

#with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    #s.connect((HOST, PORT))
    #s.sendall(b"Hello, world")
    #data = s.recv(1024)

def draw_skeleton(image):
	point_color = (59, 164, 0)
	for skel in data.skeletons:
		for el in skel[1:]:
			x = (round(el.projection[0]), round(el.projection[1]))
			cv2.circle(image, x, 8, point_color, -1)

nuitrack = py_nuitrack.Nuitrack()
nuitrack.init()


devices = nuitrack.get_device_list()
for i, dev in enumerate(devices):
	print(dev.get_name(), dev.get_serial_number())
	if i == 0:
		
		print(dev.get_activation())
		nuitrack.set_device(dev)


print(nuitrack.get_version())
print(nuitrack.get_license())

nuitrack.create_modules()
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
		for skeleton in data.skeletons:
			print(getattr(skeleton.torso,'real')[2])
			#s.send(getattr(skeleton.torso,'real')[2])
			#print(getattr(skeleton.torso,'real'))

		if key == 32:
			mode = next(modes)
		if mode == "depth":
			cv2.imshow('Image', img_depth)
		if mode == "color":
			if img_color.size:
				cv2.imshow('Image', img_color)
	if key == 27:
		break

nuitrack.release()