from subscripts import ports
from menus.gestures import Gestures
from time import sleep
from menus.games.RockPaperScissor.RockPaperScissors import game as RockPaperScissors
from menus.games.RockPaperScissor import speech


baudrate = 115200
serial_port = None

def main():
    global serial_port
    serial_arr = ports.setup_ports(baudrate)
    serial_port = serial_arr[0]
    serial_port.open()
    print(serial_port)
    gestures = Gestures(serial_port)
    
    ###YOUR CODE HERE###

    RockPaperScissors(serial_port)
    

    
if __name__ == "__main__":
    main()
    