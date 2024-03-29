
import sys
import os
import serial
import glob
import io

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
sio = io.TextIOWrapper(io.BufferedRWPair(port, port))

while True:
    os.system("clear")
    servo = input("Please enter which servo to steer (0 = all): ")
    value = input("Please enter the value to write (std: 0 - 180): ")

    port.write(bytes(';', 'utf-8'))
    port.write(bytes(servo, 'utf-8'))
    port.write(bytes(value, 'utf-8'))

    port.flush()
    hello = sio.readline()
    print(hello)
    