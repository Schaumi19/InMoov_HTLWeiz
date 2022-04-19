
# For this to work, please use the "ARDUINO_CODE_NAME"_AP code for your arduinos

# Hüfte is not working, so please don't connect that yet, testing is to be done by Thomas

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
    ports = glob.glob("/dev/ttyUSB*")

for port in ports:
    try:
        if sys.platform.startswith("win"):
            s = serial.Serial(port=port.name, baudrate=baudrate)
        if sys.platform.startswith("linux"):
            s = serial.Serial(port=port, baudrate=baudrate)
        s.open()
        return_arr.append(s)
    except serial.SerialException:
        pass