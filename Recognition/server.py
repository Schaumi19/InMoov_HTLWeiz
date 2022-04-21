import socket

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

    while True:
        data = c.recv(2048)
        if not data:
            print("End of file from client. Resetting")
            break

        gesture = data.decode()
        #dist = data.split(",")[0]
        #angle = data.split(",")[1]
        #print(dist)
        #print(angle)

        print("Received '%s' from client" % data)

        #data = "Hello, " + str(addr) + ". I got this from you: '" + str(data) + "'"

        #data = data.encode()

        #c.send(data)

    c.close()