import serial
import sys
import glob
from time import sleep
from array import *

baudrate = 115200
serial_port = None

used = 0
reverse_output = 0
reverse_input = 0
useAngularSpeed = 0
min_angle = 9
max_angle = 8
min_pot = 7777
max_pot = 6667
continuousMovement = 5
goalDeadzone = 4
maxSpeed = 3
errorMinDiff = 2
errorMinAngularSpeed = 1


def main():

    global serial_port
    serial_port = SerialOpen()

    ReadConfig()
    WriteConfig()
    ReadConfig()
    '''
    global used
    global reverse_output
    global reverse_input
    global useAngularSpeed
    global min_angle
    global max_angle
    global min_pot
    global max_pot
    global continuousMovement
    global goalDeadzone
    global maxSpeed
    global errorMinDiff
    global errorMinAngularSpeed
    used = 0
    reverse_output = 1
    reverse_input = 0
    useAngularSpeed = 1
    min_angle = 30
    max_angle = 71
    min_pot = 7
    max_pot = 98
    continuousMovement = 5
    goalDeadzone = 12
    maxSpeed = 55
    errorMinDiff = 22
    errorMinAngularSpeed = 38
    '''
    WriteConfig()
    ReadConfig()

def WriteConfig():
    serial_port.write(bytes('!', 'ascii')) # Start Config Write MSG
    firstByte = used
    firstByte += reverse_output*2
    firstByte += reverse_input*4
    firstByte += useAngularSpeed*8
    MotorParamBytes = firstByte.to_bytes(1,'big')
    MotorParamBytes += min_angle.to_bytes(1,'big')
    MotorParamBytes += max_angle.to_bytes(1,'big')
    MotorParamBytes += min_pot.to_bytes(2, 'big')
    MotorParamBytes += max_pot.to_bytes(2, 'big')
    MotorParamBytes += continuousMovement.to_bytes(1,'big')
    MotorParamBytes += goalDeadzone.to_bytes(1,'big')
    MotorParamBytes += maxSpeed.to_bytes(1,'big')
    MotorParamBytes += errorMinDiff.to_bytes(1,'big')
    MotorParamBytes += errorMinAngularSpeed.to_bytes(1,'big')

    try:
        for i in range(4):
            serial_port.write(MotorParamBytes) # Write Config
        print("printed")
    except AttributeError:
        print("AttributeError")



def ReadConfig():
    # Activate Config Mode and Flush Serial Input
    while(serial_port.inWaiting()):
        SerialPrint("C") # Activate Config Mode
        while(serial_port.inWaiting()):
            serial_port.read(serial_port.inWaiting()) # Flush Serial Input
        sleep(0.5)
    print("Flush Done")

    receiving = True
    while(receiving):
        SerialPrint("?") # Request Config
        if serial_port.inWaiting():
            print("StartRec")
            serial_port.read_until(b'|')
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
            sleep(0.1)
        
# Make sure Config Mode is enabled and the Serial input puffer is at least almost empty before reading
def ReadNewPotValues():
    receiving = True
    while(receiving):
        SerialPrint("P")
        if serial_port.inWaiting():
            serial_port.read_until(b'P')
            pots = [0,0,0,0]
            print("PotValues:")
            for i in range(4):
                pots[i] = int.from_bytes(serial_port.read(2), 'little')
                print("pot" ,i,": ", pots[i])
            receiving = False;
            return pots

    

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