#author: Schaumi

import serial
import sys
import glob
from time import sleep
from array import *

baudrate = 115200
serial_port = None

''' 
motorData = [{"used":0, "reverse_output":1, "reverse_input":0, "useAngularSpeed":1, "min_angle":19, "max_angle":18, "min_pot":1777, "max_pot":1667, "continuousMovement":15, "goalDeadzone":14, "maxSpeed":13, "errorMinDiff":12, "errorMinAngularSpeed":11},
             {"used":1, "reverse_output":0, "reverse_input":1, "useAngularSpeed":0, "min_angle":29, "max_angle":28, "min_pot":2777, "max_pot":2667, "continuousMovement":25, "goalDeadzone":24, "maxSpeed":23, "errorMinDiff":22, "errorMinAngularSpeed":21},
             {"used":0, "reverse_output":1, "reverse_input":0, "useAngularSpeed":1, "min_angle":39, "max_angle":38, "min_pot":3777, "max_pot":3667, "continuousMovement":35, "goalDeadzone":34, "maxSpeed":33, "errorMinDiff":32, "errorMinAngularSpeed":31},
             {"used":1, "reverse_output":0, "reverse_input":1, "useAngularSpeed":0, "min_angle":49, "max_angle":48, "min_pot":4777, "max_pot":4667, "continuousMovement":45, "goalDeadzone":44, "maxSpeed":43, "errorMinDiff":42, "errorMinAngularSpeed":41}]
'''

motorData = [{"used":0, "reverse_output":0, "reverse_input":0, "useAngularSpeed":0, "min_angle":0, "max_angle":180, "min_pot":0, "max_pot":0, "continuousMovement":0, "goalDeadzone":0, "maxSpeed":0, "errorMinDiff":0, "errorMinAngularSpeed":0},
             {"used":0, "reverse_output":0, "reverse_input":0, "useAngularSpeed":0, "min_angle":0, "max_angle":180, "min_pot":0, "max_pot":0, "continuousMovement":0, "goalDeadzone":0, "maxSpeed":0, "errorMinDiff":0, "errorMinAngularSpeed":0},
             {"used":0, "reverse_output":0, "reverse_input":0, "useAngularSpeed":0, "min_angle":0, "max_angle":180, "min_pot":0, "max_pot":0, "continuousMovement":0, "goalDeadzone":0, "maxSpeed":0, "errorMinDiff":0, "errorMinAngularSpeed":0},
             {"used":0, "reverse_output":0, "reverse_input":0, "useAngularSpeed":0, "min_angle":0, "max_angle":180, "min_pot":0, "max_pot":0, "continuousMovement":0, "goalDeadzone":0, "maxSpeed":0, "errorMinDiff":0, "errorMinAngularSpeed":0}]
pos = 0;
                    
def main():
    global serial_port
    serial_port = SerialOpen()

    ActivateConfigMode()

    #ReadConfig()
    #WriteConfig()
    #ReadConfig()

def ManualControl(i,dir):
    global motorData
    if(motorData[i]["used"]):
        if(motorData[i]["reverse_output"]):
            dir = 1-dir
        serial_port.write(bytes(';', 'ascii')) # Start Manual Control MSG
        serial_port.write(bytes(str(i), 'ascii')) # Motor ID
        serial_port.write(bytes(',', 'ascii')) # Seperator
        serial_port.write(bytes(str(dir), 'ascii')) # Direction


def WriteConfig():
    '''Writes the Config to the Arduino'''
    global motorData
    serial_port.write(bytes('!', 'ascii')) # Start Config Write MSG
    print("Position: "+str(pos))
    serial_port.write(pos.to_bytes(1,'big')) # Write Config
    for i in range(4):
        firstByte = motorData[i]["used"]
        firstByte += motorData[i]["reverse_output"]*2
        firstByte += motorData[i]["reverse_input"]*4
        firstByte += motorData[i]["useAngularSpeed"]*8
        MotorParamBytes = firstByte.to_bytes(1,'big') # First Byte
        MotorParamBytes += motorData[i]["min_angle"].to_bytes(1,'big')
        MotorParamBytes += motorData[i]["max_angle"].to_bytes(1,'big')
        MotorParamBytes += motorData[i]["min_pot"].to_bytes(2, 'big')
        MotorParamBytes += motorData[i]["max_pot"].to_bytes(2, 'big')
        MotorParamBytes += motorData[i]["continuousMovement"].to_bytes(1,'big')
        MotorParamBytes += motorData[i]["goalDeadzone"].to_bytes(1,'big')
        MotorParamBytes += motorData[i]["maxSpeed"].to_bytes(1,'big')
        MotorParamBytes += motorData[i]["errorMinDiff"].to_bytes(1,'big')
        MotorParamBytes += motorData[i]["errorMinAngularSpeed"].to_bytes(1,'big')
        try:
            MotorbyteString = ""
            for byte in MotorParamBytes:
                MotorbyteString += str(byte) + " "
            print(MotorbyteString)
            serial_port.write(MotorParamBytes) # Write Config
            print("printed"+str(i))
        except AttributeError:
            print("AttributeError")

def ActivateConfigMode():
    '''Activates Config Mode on the Arduino'''
    global serial_port
    while(serial_port.inWaiting()):
        SerialPrint("C")
        flushSerial()
        sleep(0.5)
    print("ConfigMode Activated")

def flushSerial(sleepTime=0.1):
    '''Flushes the Serial Buffer'''
    global serial_port
    while(serial_port.inWaiting()):
        serial_port.read(serial_port.inWaiting())
        sleep(sleepTime)

def ReadConfig():
    '''Reads the Config from the Arduino and prints it to the console'''

    global motorData
    global pos
    global serial_port

    ActivateConfigMode()

    receiving = True
    while(receiving):
        SerialPrint("?") # Request Config
        if serial_port.inWaiting():
            print("StartRec")
            serial_port.read_until(b'|')
            pos = int.from_bytes(serial_port.read(), 'big')
            print("Position: " + str(pos))
            for i in range(4):
                firstByte = serial_port.read()
                motorData[i]["used"] = int.from_bytes(firstByte, 'big') & 1
                motorData[i]["reverse_output"] = int.from_bytes(firstByte, 'big')>>1 & 1
                motorData[i]["reverse_input"] = int.from_bytes(firstByte, 'big')>>2 & 1
                motorData[i]["useAngularSpeed"] = int.from_bytes(firstByte, 'big')>>3 & 1
                motorData[i]["min_angle"] = int.from_bytes(serial_port.read(), 'big')
                motorData[i]["max_angle"] = int.from_bytes(serial_port.read(), 'big')
                motorData[i]["min_pot"] = int.from_bytes(serial_port.read(2), 'little')
                motorData[i]["max_pot"] = int.from_bytes(serial_port.read(2), 'little')
                motorData[i]["continuousMovement"] = int.from_bytes(serial_port.read(), 'big')
                motorData[i]["goalDeadzone"] = int.from_bytes(serial_port.read(), 'big')
                motorData[i]["maxSpeed"] = int.from_bytes(serial_port.read(), 'big')
                motorData[i]["errorMinDiff"] = int.from_bytes(serial_port.read(), 'big')
                motorData[i]["errorMinAngularSpeed"] = int.from_bytes(serial_port.read(), 'big')
                print("Motor "+str(i)+":")
                print("used: "+str(motorData[i]["used"]))
                print("reverse_output: "+str(motorData[i]["reverse_output"]))
                print("reverse_input: "+str(motorData[i]["reverse_input"]))
                print("useAngularSpeed: "+str(motorData[i]["useAngularSpeed"]))
                print("min_angle: "+str(motorData[i]["min_angle"]))
                print("max_angle: "+str(motorData[i]["max_angle"]))
                print("min_pot: "+str(motorData[i]["min_pot"]))
                print("max_pot: "+str(motorData[i]["max_pot"]))
                print("continuousMovement: "+str(motorData[i]["continuousMovement"]))
                print("goalDeadzone: "+str(motorData[i]["goalDeadzone"]))
                print("maxSpeed: "+str(motorData[i]["maxSpeed"]))
                print("errorMinDiff: "+str(motorData[i]["errorMinDiff"]))
                print("errorMinAngularSpeed: "+str(motorData[i]["errorMinAngularSpeed"]))
                print("")
            print("EndRec")
            receiving = False;
            sleep(0.1)
        sleep(0.3)
    flushSerial(0.5)
        
# Make sure Config Mode is enabled and the Serial input puffer is at least almost empty before reading
def ReadNewPotValues():
    """Reads the PotValues from the Arduino and returns them as an array"""
    receiving = True
    while(receiving):
        SerialPrint("P")
        sleep(0.5)
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
    """Prints a msg + \n over Serial"""
    send_msg += "\n" # Without the newline the newline the arduino takes far longer to recognize the msg end
    print("Send: " + send_msg)
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

    # Selectes the right function for the current OS and gets all available ports
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
    '''Reads from the serial port until the specified byte is received'''
    data = b''
    while True:
        if serial_port.inWaiting() > 0:
            received_byte = serial_port.read()
            data += received_byte
            if received_byte == byte:
                break
    return data

def WrongFile():
    print('\033[91m' + "If you don't know what you are doing, don't touch this file")
    print("This file is only for testing purposes")
    print("Press Ctrl+C to exit and open ActuatorControl_UI.py"+'\033[0m')
    input("Press Enter to continue using this File")
    main()

if __name__ == "__main__":
    WrongFile()