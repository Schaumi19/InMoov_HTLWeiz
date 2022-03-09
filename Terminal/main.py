# -- Global imports -- #


import menu
import ports
import sys
import threading
import glob



# -- Global variable declaration -- #


platform = sys.platform
baudrate = 115200

serial_arr = []



# -- Global script -- #


def main():

    global serial_arr
    # Initialize serial ports list for the first time
    serial_arr = ports.setup_ports(platform, baudrate)
    serial_arr = ports.sort_ports(serial_arr)

    # Start a new thread for the menu
    threading.Thread(target=menu.main_menu, args=[serial_arr, glob.glob("/dev/tty[A-Za-z]*")]).start()


if __name__ == '__main__':
    main()
