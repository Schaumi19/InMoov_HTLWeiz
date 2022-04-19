
import sys
import os
import serial
import glob
import time

ports = []


baudrate = 115200


if sys.platform.startswith("win"):
    from serial.tools import list_ports
    ports = list_ports.comports()

if sys.platform.startswith("linux"):
    ports = glob.glob("/dev/ttyUSB*")

os.system("clear")

port = [None for x in range(len(ports))]

for p in ports:
    if sys.platform.startswith("win"):
        port[ports.index(p)] = serial.Serial(port=p.name, baudrate=baudrate)

    if sys.platform.startswith("linux"):
        port[ports.index(p)] = serial.Serial(port=p, baudrate=baudrate)

for p in port:

    time.sleep(2)

    p.write(bytes('6', 'utf-8'))
    p.write(bytes('9', 'utf-8'))

    print("Port " + str(port.index(p)) + " Byte1: " + str(p.read().decode('utf-8')))
    print("Port " + str(port.index(p)) + " Byte2: " + str(p.read().decode('utf-8')))
