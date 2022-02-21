# -- Global imports -- #

import menu
import sys
import glob
import serial



# -- Global variable declaration -- #

platform = sys.platform
baudrate = 112500



# -- Global script -- #

def main():

    serial_arr = setup_ports()
    for s in serial_arr:
        print(str(s))

    menu.main_menu()


def setup_ports():
    """Returns all serial ports that can be connected to
    """

    temp_ports = list()

    if platform.startswith("win"):
        temp_ports = serial.tools.list_ports()

    elif platform.startswith("linux"):
        temp_ports = glob.glob("/dev/tty[A-Za-z]*")

    return_arr = list()
    for port in temp_ports:
        print(port)
        try:
            s = serial.Serial(port=port, baudrate=baudrate)
            s.close()
            return_arr.append(s)
        except serial.SerialException:
            pass

    return return_arr





if __name__ == '__main__':
    main()
