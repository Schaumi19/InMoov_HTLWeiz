import serial
import sys
import glob
from time import sleep

baudrate = 115200
serial_port = None

def main():
    global serial_port
    serial_port = SerialOpen()
    SerialPrint("!")
    print("!")
    sleep(1)
    while(1):
        line = serial_port.readline()   # read a '\n' terminated line
        print(line)

    

def SerialOpen():
    """Gets the Serial-port of the one Connected Arduino"""
    serial_arr = setup_ports(baudrate)
    if len(serial_arr) > 1:
        print("More than one Arduino Connected")
        exit()
    elif len(serial_arr) == 0:
        print("No Arduino Connected")
        exit()

    serial_port = serial_arr[0]
    serial_port.open()
    sleep(2.5) ## The Arduino needs to restart
    return serial_port

def SerialPrint(send_msg):
    """Prints a msg over Serial"""
    send_msg += "\n" # Without the newline the newline the arduino takes far longer to recognize the msg end
    serial_port.write(bytes(send_msg, 'ascii'))
    try:
        try:
            try:
                serial_port.write(bytes(send_msg, 'ascii'))
            except AttributeError:
                print("AttributeError")
        except serial.SerialException:
            print("SerialException")
    except TypeError:
        print("TypeError")

def setup_ports(baudrate: int):
    """Returns all serial ports that can be connected to"""

    temp_ports = list()

    if sys.platform.startswith("win"):
        from serial.tools import list_ports
        temp_ports = list_ports.comports()

    elif sys.platform.startswith("linux"):
        temp_ports = glob.glob("/dev/tty[A-Za-z]*")

    return_arr = list()
    for port in temp_ports:
        try:
            if sys.platform.startswith("win"):
                s = serial.Serial(port=port.name, baudrate=baudrate, timeout=1)
            if sys.platform.startswith("linux"):
                s = serial.Serial(port=port, baudrate=baudrate, timeout=1)
            s.close()
            return_arr.append(s)
        except serial.SerialException:
            print("Error on: " + port.name)

    return return_arr
        

if __name__ == "__main__":
    main()




