
import sys
import os
import serial
import glob

ports = []


baudrate = 115200


if sys.platform.startswith("win"):
    from serial.tools import list_ports
    ports = list_ports.comports()

if sys.platform.startswith("linux"):
    ports = glob.glob("/dev/ttyUSB[A-Za-z]*")

os.system("clear")

print("Please enter which port to steer:\n")
for port in ports:
    if sys.platform.startswith("win"):
        print(port.name)

    if sys.platform.startswith("linux"):
        print(port)

choice = input("\nPort: ")

port = serial.Serial(port=choice, baudrate=baudrate)

while(True):
    os.system("clear")
    servo = int(input("Please enter which servo to steer (0 = all): "))
    value = int(input("Please enter the value to write (std: 0 - 180): "))

    port.write(servo)
    port.write(value)