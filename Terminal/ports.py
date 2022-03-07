# -- Global imports -- #


import serial
import glob
import sys
import time



# -- Global script -- #


def setup_ports(platform: str, baudrate: int):
    """Returns all serial ports that can be connected to
    """

    temp_ports = list()

    if platform.startswith("win"):
        temp_ports = serial.tools.list_ports()

    elif platform.startswith("linux"):
        temp_ports = glob.glob("/dev/tty[A-Za-z]*")

    return_arr = list()
    for port in temp_ports:
        try:
            s = serial.Serial(port=port, baudrate=baudrate)
            s.close()
            return_arr.append(s)
        except serial.SerialException:
            pass

    return return_arr


def sort_ports(ports: list[serial.Serial]):
    """used to sort a given SerialPort list according to the ACP

        Args:
            ports (list[serial.Serial]): array of ports to sort
    """
    ports_sorted = [0 for x in range(9)]

    for port in ports:
        try:
            try:
                try:
                    port.open()
                except AttributeError:
                    raise OSError
            except OSError:
                raise serial.SerialException
        except serial.SerialException:
            pass

        ACP1 = 0
        ACP2 = 0

        try:
            ACP1 = int.from_bytes(port.read(), sys.byteorder)
            ACP2 = int.from_bytes(port.read(), sys.byteorder)
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
    
    return ports_sorted


import sys
if __name__ == '__main__':
    print(sort_ports(setup_ports(sys.platform, 115200)))
