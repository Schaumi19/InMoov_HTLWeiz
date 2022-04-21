import socket
import multiprocessing
import gestures

SERVER_ADDRESS = '127.0.0.1'
SERVER_PORT = 22222

s = socket.socket()
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
s.bind((SERVER_ADDRESS, SERVER_PORT))
s.listen(5)
gestures = gestures.Gestures()


while True:
    c, addr = s.accept()

    while True:

        

        data = c.recv(2048)
        if not data:
            break

        gesture = data.decode()

        data = "Hello, " + str(addr) + ". I got this from you: '" + str(data) + "'"

        data = data.encode()

        c.send(data)

    c.close()