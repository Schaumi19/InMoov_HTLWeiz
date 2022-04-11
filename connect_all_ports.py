
import sys
import os
import serial
import glob

ports: list[serial.Serial] = []


baudrate = 115200


if sys.platform.startswith("win"):
    from serial.tools import list_ports
    ports = list_ports.comports()

if sys.platform.startswith("linux"):
    ports = glob.glob("/dev/ttyUSB[A-Za-z]*")

for port in ports:
    try:
        if sys.platform.startswith("win"):
            s = serial.Serial(port=port.name, baudrate=baudrate)
        if sys.platform.startswith("linux"):
            s = serial.Serial(port=port, baudrate=baudrate)
        s.close()
        return_arr.append(s)
    except serial.SerialException:
        pass