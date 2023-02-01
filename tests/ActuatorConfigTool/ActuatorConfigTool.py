import serial
import sys
import glob
from time import sleep

baudrate = 115200
serial_port = None

used = 1
reverse_output = 1
reverse_input = 1
useAngularSpeed = 1
angle = 1
angle = 1
continuousMovement = 1
goalDeadzone = 1
maxSpeed = 1
max_angle = 1
errorMinDiff = 1
errorMinAngularSpeed = 1
errorMinDiff = 1

def main():
    global serial_port
    serial_port = SerialOpen()
    SerialPrint("!")
    print("!")
    sleep(1)


    for i in range(4):
        #MotorParamBytes [12]
        MotorParamBytes = 0
        MotorParamBytes[0] = used
        MotorParamBytes[0] += reverse_output * 2
        MotorParamBytes[0] += reverse_input * 4
        MotorParamBytes[0] += useAngularSpeed * 8
        min_angleBytes = min_angle.to_byte(2,'big')
        MotorParamBytes[1] = min_angleBytes[0]
        MotorParamBytes[2] = min_angleBytes[1]
        max_angleBytes = max_angle.to_bytes(2,'big')
        MotorParamBytes[3] = max_angleBytes[0]
        MotorParamBytes[4] = max_angleBytes[1]
        MotorParamBytes[5] = continuousMovement
        MotorParamBytes[6] = goalDeadzone
        MotorParamBytes[7] = maxSpeed
        MotorParamBytes[8] = max_angle
        MotorParamBytes[9] = errorMinDiff
        MotorParamBytes[10] = errorMinAngularSpeed
        MotorParamBytes[11] = errorMinDiff
        for x in range(12):
            try:
                serial_port.write(MotorParamBytes[x])
            except AttributeError:
                print("AttributeError")
            


    while(1):
        #line = serial_port.readline()   # read a '\n' terminated line
        #print(line)

        #for (byte i = 0; i < 4; i++)

        firstByte = serial_port.read()
        used = firstByte & 1
        reverse_output = firstByte & 2
        reverse_input = firstByte & 4
        useAngularSpeed = firstByte & 8
        min_angle = serial_port.read()
        min_angle += serial_port.read() << 8
        max_angle = serial_port.read()
        max_angle = serial_port.read() << 8
        continuousMovement = serial_port.read()
        goalDeadzone = serial_port.read()
        maxSpeed = serial_port.read()
        max_angle = serial_port.read()
        errorMinDiff = serial_port.read()
        errorMinAngularSpeed = serial_port.read()
        errorMinDiff = serial_port.read()
        
        print(used)
        print(reverse_output)
        print(reverse_input)
        print(useAngularSpeed)
        print(angle)
        print(angle)
        print(continuousMovement)
        print(goalDeadzone)
        print(maxSpeed)
        print(max_angle)
        print(errorMinDiff)
        print(errorMinAngularSpeed)
        print(errorMinDiff)


    

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




