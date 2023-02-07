import serial
import sys
import glob
from time import sleep
from array import *

baudrate = 115200
serial_port = None



def main():

    used = 1
    reverse_output = 1
    reverse_input = 1
    useAngularSpeed = 1
    min_angle = 2
    max_angle = 3
    min_pot = 4
    max_pot = 5
    continuousMovement = 6
    goalDeadzone = 7
    maxSpeed = 8
    errorMinDiff = 9
    errorMinAngularSpeed = 10
    
    global serial_port
    serial_port = SerialOpen()
    #SerialPrint("!")
    serial_port.write(bytes('!', 'ascii'))
    print("!")
    sleep(1)


    #for i in range(4):
        #MotorParamBytes [12]
    firstByte = used
    firstByte += reverse_output*2
    firstByte += reverse_input*4
    firstByte += useAngularSpeed*8
    MotorParamBytes = firstByte.to_bytes(1,'big')
    MotorParamBytes += min_angle.to_bytes(1,'big')
    MotorParamBytes += max_angle.to_bytes(1,'big')
    print(min_pot.to_bytes(2, 'big'))
    MotorParamBytes += min_pot.to_bytes(2, 'big')
    MotorParamBytes += max_pot.to_bytes(2, 'big')
    MotorParamBytes += continuousMovement.to_bytes(1,'big')
    MotorParamBytes += goalDeadzone.to_bytes(1,'big')
    MotorParamBytes += maxSpeed.to_bytes(1,'big')
    MotorParamBytes += errorMinDiff.to_bytes(1,'big')
    MotorParamBytes += errorMinAngularSpeed.to_bytes(1,'big')

    print(MotorParamBytes)
    try:
        for i in range(4):
            print(serial_port.write(MotorParamBytes))
        print("printed")
    except AttributeError:
        print("AttributeError")
    
    sleep(1)
    SerialPrint("CC") # Somehow only one C desn't work
    sleep(1)
    SerialPrint("CC")
    while(serial_port.inWaiting()):
        while(serial_port.inWaiting()):
            print(serial_port.read(serial_port.inWaiting()))
        sleep(1)
    print("Flush Done")
    sleep(1)
    receiving = True
    while(receiving):
        #line = serial_port.readline()   # read a '\n' terminated line
        #print(line)

        #for (byte i = 0; i < 4; i++)
        if serial_port.inWaiting():
            print("StartRec")
            print(serial_port.read_until(b'|'))
            print("Receiving")
            for i in range(4):
                firstByte = serial_port.read()
                used = int.from_bytes(firstByte, 'big') & 1
                reverse_output = int.from_bytes(firstByte, 'big')>>1 & 1
                reverse_input = int.from_bytes(firstByte, 'big')>>2 & 1
                useAngularSpeed = int.from_bytes(firstByte, 'big')>>3 & 1
                min_angle = int.from_bytes(serial_port.read(), 'big')
                max_angle = int.from_bytes(serial_port.read(), 'big')
                min_pot = int.from_bytes(serial_port.read(2), 'little')
                max_pot = int.from_bytes(serial_port.read(2), 'little')
                continuousMovement = int.from_bytes(serial_port.read(), 'big')
                goalDeadzone = int.from_bytes(serial_port.read(), 'big')
                maxSpeed = int.from_bytes(serial_port.read(), 'big')
                errorMinDiff = int.from_bytes(serial_port.read(), 'big')
                errorMinAngularSpeed = int.from_bytes(serial_port.read(), 'big')

            print("used " , used)
            print("reverse_output " , reverse_output)
            print("reverse_input" , reverse_input)
            print("useAngularSpeed " , useAngularSpeed)
            print("min_angle " , min_angle)
            print("max_angle " , max_angle)
            print("min_pot " , min_pot)
            print("max_pot " , max_pot)
            print("continuousMovement " , continuousMovement)
            print("goalDeadzone " , goalDeadzone)
            print("maxSpeed " , maxSpeed)
            print("errorMinDiff " , errorMinDiff)
            print("errorMinAngularSpeed " , errorMinAngularSpeed)

            receiving = False;
        SerialPrint("?")


    

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




def read_until(byte):
    data = b''
    while True:
        if serial_port.inWaiting() > 0:
            received_byte = serial_port.read()
            data += received_byte
            if received_byte == byte:
                break
    return data



        

if __name__ == "__main__":
    main()




