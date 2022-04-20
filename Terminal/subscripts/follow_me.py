import os
import socket
serial_arr = []


def follow_me(serial_arr_param):
    global serial_arr
    serial_arr = serial_arr_param
    os.system("clear")
    SERVER_ADDRESS = '127.0.0.1'
    SERVER_PORT = 22222

    s = socket.socket()
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    s.bind((SERVER_ADDRESS, SERVER_PORT))
    s.listen(5)
    print("Listening on address %s. Kill server with Ctrl-C" %
        str((SERVER_ADDRESS, SERVER_PORT)))

    while True:
        c, addr = s.accept()
        print("\nConnection received from %s" % str(addr))

        data = c.recv(2048)
        if not data:
            print("End of file from client. Resetting")
            break
        data = data.decode()
        dist = int(data.split(",")[0])
        angle = int(data.split(",")[1])
        print(dist)
        print(angle)
        print("Received '%s' from client" % data)
        data = "Hello, " + str(addr) + ". I got this from you: '" + data + "'"
        data = data.encode()
        c.send(data)
        
        if dist > 200:
            geradeaus(angle)
        if dist < 150:
            backoff(angle)
        drehen(angle)

    

def drehen(angle):
    if not (angle > -5 and angle < 5):
        if angle > 0:
            serial_arr[0].write(bytes(";", "utf 8"))
            serial_arr[0].write(bytes(250, "utf 8"))
            serial_arr[0].write(bytes(",", "utf 8"))
            serial_arr[0].write(bytes(-250, "utf 8"))
        elif angle < 0:
            serial_arr[0].write(bytes(";", "utf 8"))
            serial_arr[0].write(bytes(-250, "utf 8"))
            serial_arr[0].write(bytes(",", "utf 8"))
            serial_arr[0].write(bytes(250, "utf 8"))
    else:
        serial_arr[0].write(bytes(";", "utf 8"))
        serial_arr[0].write(bytes(0, "utf 8"))
        serial_arr[0].write(bytes(",", "utf 8"))
        serial_arr[0].write(bytes(0, "utf 8"))


def geradeaus(angle):
    if not (angle > -5 and angle < 5):
        if angle > 0:
            serial_arr[0].write(bytes(";", "utf 8"))
            serial_arr[0].write(bytes(425, "utf 8"))
            serial_arr[0].write(bytes(",", "utf 8"))
            serial_arr[0].write(bytes(375, "utf 8"))
        elif angle < 0:
            serial_arr[0].write(bytes(";", "utf 8"))
            serial_arr[0].write(bytes(375, "utf 8"))
            serial_arr[0].write(bytes(",", "utf 8"))
            serial_arr[0].write(bytes(425, "utf 8"))
    else:
        serial_arr[0].write(bytes(";", "utf 8"))
        serial_arr[0].write(bytes(400, "utf 8"))
        serial_arr[0].write(bytes(",", "utf 8"))
        serial_arr[0].write(bytes(400, "utf 8"))


def backoff(angle):
    if not (angle > -5 and angle < 5):
        if angle > 0:
            serial_arr[0].write(bytes(";", "utf 8"))
            serial_arr[0].write(bytes(-425, "utf 8"))
            serial_arr[0].write(bytes(",", "utf 8"))
            serial_arr[0].write(bytes(-375, "utf 8"))
        elif angle < 0:
            serial_arr[0].write(bytes(";", "utf 8"))
            serial_arr[0].write(bytes(-375, "utf 8"))
            serial_arr[0].write(bytes(",", "utf 8"))
            serial_arr[0].write(bytes(-425, "utf 8"))
    else:
        serial_arr[0].write(bytes(";", "utf 8"))
        serial_arr[0].write(bytes(-400, "utf 8"))
        serial_arr[0].write(bytes(",", "utf 8"))
        serial_arr[0].write(bytes(-400, "utf 8"))
