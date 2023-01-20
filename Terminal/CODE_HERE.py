from subscripts import ports
from menus.gestures import Gestures
import serial
from time import sleep

baudrate = 115200
serial_port = None



def main():
    global serial_port
    serial_arr = ports.setup_ports(baudrate)
    serial_port = serial_arr[0]
    serial_port.open()
    print(serial_port)
    #serial_port = serial.Serial(port="COM3", baudrate=baudrate)
    #print(serial_port)
    gestures = Gestures(serial_port)
    sleep(2.5)



    # Please code here
    # Exampl
    while(1):
        gestures.right_shoulder(0,30)
        gestures.right_hand_fingers(0,0)
        gestures.right_hand_rotate(20)
        gestures.left_shoulder(0,120)
        gestures.left_hand_fingers(0,180)
        gestures.left_hand_rotate(150)
        gestures.torso(2,30)
        gestures.head(0,100)
        sleep(5)
        gestures.head(0,70)
        sleep(5)
        gestures.head(0,30)
        sleep(5)
        gestures.head(0,70)
        gestures.right_shoulder(0,130)
        gestures.right_hand_fingers(0,180)
        gestures.right_hand_rotate(120)
        gestures.left_shoulder(0,30)
        gestures.left_hand_fingers(0,0)
        gestures.left_hand_rotate(20)
        gestures.torso(2,130)
        sleep(5)
        gestures.head(0,100)
        sleep(5)
        gestures.head(0,120)
        sleep(5)
    # Rotates the left hand to the angle of 25



    sleep(2.5)


if __name__ == "__main__":
    main()
