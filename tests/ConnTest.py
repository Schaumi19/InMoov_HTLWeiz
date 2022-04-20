# Importing Libraries
import serial
import time
arduino = serial.Serial(port='COM4', baudrate=115200, timeout=.1)
def write_read(x,y):
    arduino.write(bytes(x, 'utf-8'))
    arduino.write(bytes(',', 'utf-8'))
    arduino.write(bytes(y, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    time.sleep(0.05)
    data1 = arduino.readline()
    return str(data)+' '+str(data1)
while True:
    num = input("Enter a number: ") # Taking input from user
    num1 = input("Enter a number: ") # Taking input from user
    value = write_read(num,num1)
    print(value) # printing the value