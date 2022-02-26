# -- Global imports -- #

import serial
import glob



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
            ports (list[serial.Serial]): ports array to sort
    """
    ports_sorted = [0 for x in range(8)]

    for port in ports:
        ACP1 = port.read()
        ACP2 = port.read()

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

        elif ACP1 == 5:
            if ACP2 == 1:
                ports_sorted[5] = port
            elif ACP2 == 3:
                ports_sorted[6] = port
    
    return ports_sorted


def serial_comm(ports: list[serial.Serial], portNum: int, servoNum: int, val: int):
    ports[portNum].write(str(servoNum) + "\n" + str(val))
