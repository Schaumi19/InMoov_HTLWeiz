
import os



def steering(serial_arr_param):
    global serial_arr
    serial_arr = serial_arr_param

    # Loop that runs while the child process is alive (The user hasn't pressed a key)
    while True:
        os.system("clear")

        print("Please enter the right combination to steer the body part: ")
        choice1 = input("Enter the side of the body (l... left, m... middle, r... right)   ")
        choice2 = input("Enter the body part (h... hand/head, a... actuator, b... board)   ")
        try:
            while True:
                os.system("clear")

                if choice2 != "b":
                    choice3 = input("Enter the servo to steer (type quit to quit)   ")
                    choice4 = input("Enter the new angle of the body part (0->180)   ")
                    if choice3 == "quit" or choice4 == "quit":
                        return

                if choice1 == "l":
                    if choice2 == "h":
                        write_serial(choice3, choice4, 2)
                    if choice2 == "a":
                        write_serial(choice3, choice4, 3)
                
                if choice1 == "m":
                    if choice2 == "h":
                        write_serial(choice3, choice4, 4)
                    if choice2 == "a":
                        write_serial(choice3, choice4, 5)

                    if choice2 == "b":
                        choice4 = str()
                        while choice4 != "quit":
                            os.system("clear")
                            choice4 = input("Please enter the command for the board   ")
                            new_c4 = choice4.split()
                            write_serial(new_c4[0], new_c4[1], 0)

                if choice1 == "r":
                    if choice2 == "h":
                        write_serial(choice3, choice4, 6)
                    if choice2 == "a":
                        write_serial(choice3, choice4, 7)
                print("Carl")
        except AttributeError:
            print("No servo attached")

        q = input("\nPress y or n to quit or not\n").capitalize()
        if q == "Y":
            return


def write_serial(self, servo_num, value, serial_index):
    serial_arr[serial_index].write(bytes(";" , 'ascii'))
    serial_arr[serial_index].write(bytes(str(servo_num) , 'ascii'))
    serial_arr[serial_index].write(bytes("," , 'ascii'))
    serial_arr[serial_index].write(bytes(str(value) , 'ascii'))
    serial_arr[serial_index].write(bytes(" " , 'ascii'))
