import os
import getch
import threading
import multiprocessing
import ports
from PyNuitrack import py_nuitrack
import cv2 
from itertools import cycle
from importlib_metadata import PathDistribution
from matplotlib.pyplot import get
import numpy as np
import time



baudrate = 115200
backoff_dist = 100
forward_dist = 150

serial_arr = []
dist = ((forward_dist + backoff_dist) / 2)
angle = 0



def follow_me(serial_arr_param):

    global dist
    global angle

    global serial_arr
    serial_arr = serial_arr_param
    os.system("clear")

    quit = multiprocessing.Process(target=check_quit)
    quit.start()

    data_tracking = threading.Thread(target=Skeletondata)
    data_tracking.start()

    while True:
        #print(dist, angle)
        if dist > forward_dist:
            print("Going forward!")
            try:
                geradeaus()
            except AttributeError:
                pass
        elif dist < backoff_dist:
            print("Backing off!")
            try:
                backoff()
            except AttributeError:
                pass
        else:
            print("Turning (maybe)")
            try:
                drehen_vllt()
            except AttributeError:
                pass

    

def drehen_vllt():
    if not (angle > -25 and angle < 25):
        if angle > 0:
            serial_arr[0].write(bytes(";", "utf 8"))
            serial_arr[0].write(bytes("350", "utf 8"))
            serial_arr[0].write(bytes(",", "utf 8"))
            serial_arr[0].write(bytes("-350", "utf 8"))
        elif angle < 0:
            serial_arr[0].write(bytes(";", "utf 8"))
            serial_arr[0].write(bytes("-350", "utf 8"))
            serial_arr[0].write(bytes(",", "utf 8"))
            serial_arr[0].write(bytes("350", "utf 8"))
    else:
        serial_arr[0].write(bytes(";", "utf 8"))
        serial_arr[0].write(bytes("0", "utf 8"))
        serial_arr[0].write(bytes(",", "utf 8"))
        serial_arr[0].write(bytes("0", "utf 8"))


def geradeaus():
    if not (angle > -25 and angle < 25):
        if angle > 0:
            serial_arr[0].write(bytes(";", "utf 8"))
            serial_arr[0].write(bytes("425", "utf 8"))
            serial_arr[0].write(bytes(",", "utf 8"))
            serial_arr[0].write(bytes("375", "utf 8"))
        elif angle < 0:
            serial_arr[0].write(bytes(";", "utf 8"))
            serial_arr[0].write(bytes("375", "utf 8"))
            serial_arr[0].write(bytes(",", "utf 8"))
            serial_arr[0].write(bytes("425", "utf 8"))
    else:
        serial_arr[0].write(bytes(";", "utf 8"))
        serial_arr[0].write(bytes("400", "utf 8"))
        serial_arr[0].write(bytes(",", "utf 8"))
        serial_arr[0].write(bytes("400", "utf 8"))


def backoff():
    if not (angle > -25 and angle < 25):
        if angle > 0:
            serial_arr[0].write(bytes(";", "utf 8"))
            serial_arr[0].write(bytes("-425", "utf 8"))
            serial_arr[0].write(bytes(",", "utf 8"))
            serial_arr[0].write(bytes("-375", "utf 8"))
        elif angle < 0:
            serial_arr[0].write(bytes(";", "utf 8"))
            serial_arr[0].write(bytes("-375", "utf 8"))
            serial_arr[0].write(bytes(",", "utf 8"))
            serial_arr[0].write(bytes("-425", "utf 8"))
    else:
        serial_arr[0].write(bytes(";", "utf 8"))
        serial_arr[0].write(bytes("-400", "utf 8"))
        serial_arr[0].write(bytes(",", "utf 8"))
        serial_arr[0].write(bytes("-400", "utf 8"))



def Skeletondata():

    def draw_skeleton(image):
        point_color = (59, 164, 0)
        for skel in data.skeletons:
            for el in skel[1:]:
                x = (round(el.projection[0]), round(el.projection[1]))
                cv2.circle(image, x, 8, point_color, -1)

    global dist
    global angle

    nuitrack = py_nuitrack.Nuitrack()
    nuitrack.init()


    devices = nuitrack.get_device_list()
    for i, dev in enumerate(devices):
        #print(dev.get_name(), dev.get_serial_number())
        if i == 0:

            #print(dev.get_activation())
            nuitrack.set_device(dev)


    #print(nuitrack.get_version())
    #print(nuitrack.get_license())
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
        img_depth = nuitrack.get_depth_data()

        if img_depth.size:
            cv2.normalize(img_depth, img_depth, 0, 255, cv2.NORM_MINMAX)
            img_depth = np.array(cv2.cvtColor(img_depth,cv2.COLOR_GRAY2RGB), dtype=np.uint8)
            img_color = nuitrack.get_color_data()
            draw_skeleton(img_depth)
            draw_skeleton(img_color)
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



def check_quit():
    getch.getch()



if __name__ == '__main__':
    follow_me(ports.sort_ports(ports.setup_ports(baudrate)))
