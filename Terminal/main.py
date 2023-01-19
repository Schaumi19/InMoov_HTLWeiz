# -- Global imports -- #


import menu
import ports
import sys
import threading
import glob



# -- Global variable declaration -- #


baudrate = 115200

serial_port = None



# -- Global script -- #


def main():

    global serial_port
    # Initialize serial ports list for the first time
    serial_arr = ports.setup_ports(baudrate)
    serial_port = ports.sort_ports(serial_arr)

    # Start a new thread for the menu
    threading.Thread(target=menu.main_menu, args=[serial_port, baudrate]).start()


if __name__ == '__main__':
    main()
