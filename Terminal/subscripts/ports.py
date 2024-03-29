# -- Global imports -- #


import serial
import glob
import sys
import time
import threading



# -- Global script -- #


def setup_ports(baudrate: int):
    """Returns all serial ports that can be connected to
    """

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
                s = serial.Serial(port=port.name, baudrate=baudrate)
            if sys.platform.startswith("linux"):
                s = serial.Serial(port=port, baudrate=baudrate)
            s.close()
            return_arr.append(s)
        except serial.SerialException:
            print("Error on: " + port.name)

    return return_arr


ports_sorted = []
def sort_ports(ports):
    """used to sort a given SerialPort list according to the ACP

        Args:
            ports (list[serial.Serial]): array of ports to sort
    """
    global ports_sorted
    ports_sorted = [0 for x in range(9)]

    threads = [0 for x in range(len(ports))]
    for port in ports:
        threads[ports.index(port)] = threading.Thread(target=connect_port, args=(port,))
        threads[ports.index(port)].start()

    for thread in threads:
        while thread.is_alive():
            pass

    return ports_sorted


def connect_port(port: serial.Serial):
    global ports_sorted
    try:
        try:
            try:
                port.open()
            except AttributeError:
                raise OSError
        except serial.SerialException:
            raise OSError
    except OSError:
        pass

    ACP1 = 0
    ACP2 = 0

    try:
        port.timeout = 2
        ACP1 = int.from_bytes(port.read(), sys.byteorder)
        ACP2 = int.from_bytes(port.read(), sys.byteorder)
        port.timeout = 100
        print(ACP1, ACP2)
    except serial.SerialException:
        pass

    if ACP1 == 1:
        ports_sorted[0] = port

    elif ACP1 == 2:
        ports_sorted[1] = port

    elif ACP1 == 3:
        if ACP2 == 1:
            ports_sorted[2] = port
        elif ACP2 == 3:
            ports_sorted[3] = port

    elif ACP1 == 4:
        if ACP2 == 2:
            ports_sorted[4] = port
        if ACP2 == 3:
            ports_sorted[5] = port

    elif ACP1 == 5:
        if ACP2 == 1:
            ports_sorted[6] = port
        elif ACP2 == 3:
            ports_sorted[7] = port
