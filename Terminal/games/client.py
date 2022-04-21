import socket


SERVER_ADDRESS = '127.0.0.1'
SERVER_PORT = 22222

c = socket.socket()
c.connect((SERVER_ADDRESS, SERVER_PORT))
print("Connected to " + str((SERVER_ADDRESS, SERVER_PORT)))

while True:
    #data = data.encode()
    #c.send(data)

    c.send(bytes(input(), 'ascii'))

    data = c.recv(1024)
    data = data.decode()

    print(data + '\n')
