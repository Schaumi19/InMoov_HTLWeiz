import ports
import sys
import glob
from menus.gestures import Gestures

baudrate = 115200
serial_port = None



def main():
    global serial_port
    serial_arr = ports.setup_ports(baudrate)
    serial_port = ports.sort_ports(serial_arr)
    gestures = Gestures(serial_port)

    # Please code here
    # Example
    gestures.left_hand_rotate(25)
    # Rotates the left hand to the angle of 25



if __name__ == "__main__":
    main()
