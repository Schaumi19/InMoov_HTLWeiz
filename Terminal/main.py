# -- Global imports -- #


import menu
import ports

import sys
import threading



# -- Global variable declaration -- #


platform = sys.platform
baudrate = 112500



# -- Global script -- #


def main():

    serial_arr = ports.setup_ports(platform, baudrate)
    ports.sort_ports(serial_arr)

    threading.Thread(target=menu.main_menu).start()



if __name__ == '__main__':
    main()
