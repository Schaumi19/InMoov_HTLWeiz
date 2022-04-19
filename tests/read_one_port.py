
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

print("Please enter which port to steer:\n")
for port in ports:
    if sys.platform.startswith("win"):
        print(port.name)

    if sys.platform.startswith("linux"):
        print(port)

choice = input("\nPort: ")

port = serial.Serial(port=choice, baudrate=baudrate)
port.read()
port.read()
port.read()

os.system("clear")
while True:
    a = port.read().decode("utf 8")
    print(a)
    a = port.read().decode("utf 8")
    print(ord(a))
    a = port.read().decode("utf 8")
    print(ord(a))
    a = port.read().decode("utf 8")
    print(ord(a))
