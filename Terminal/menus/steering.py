
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
                        serial_arr[2].write(bytes(";" , 'ascii'))
                        serial_arr[2].write(bytes(str(choice3) , 'ascii'))
                        serial_arr[2].write(bytes("," , 'ascii'))
                        serial_arr[2].write(bytes(str(choice4) , 'ascii'))
                    if choice2 == "a":
                        serial_arr[3].write(bytes(";" , 'ascii'))
                        serial_arr[3].write(bytes(str(choice3) , 'ascii'))
                        serial_arr[3].write(bytes("," , 'ascii'))
                        serial_arr[3].write(bytes(str(choice4) , 'ascii'))
                
                if choice1 == "m":
                    if choice2 == "h":
                        serial_arr[4].write(bytes(";" , 'ascii'))
                        serial_arr[4].write(bytes(str(choice3) , 'ascii'))
                        serial_arr[4].write(bytes("," , 'ascii'))
                        serial_arr[4].write(bytes(str(choice4) , 'ascii'))
                    if choice2 == "a":
                        serial_arr[5].write(bytes(";" , 'ascii'))
                        serial_arr[5].write(bytes(str(choice3) , 'ascii'))
                        serial_arr[5].write(bytes("," , 'ascii'))
                        serial_arr[5].write(bytes(str(choice4) , 'ascii'))

                    if choice2 == "b":
                        choice4 = str()
                        while choice4 != "quit":
                            os.system("clear")
                            choice4 = input("Please enter the command for the board   ")
                            new_c4 = choice4.split()
                            print("working")
                            serial_arr[0].write(bytes(";" , 'ascii'))
                            print("done1")
                            serial_arr[0].write(bytes(str(new_c4[0]) , 'ascii'))
                            print("done2")
                            serial_arr[0].write(bytes("," , 'ascii'))
                            print("done3")
                            serial_arr[0].write(bytes(str(new_c4[1]) , 'ascii'))
                            print("done4")

                if choice1 == "r":
                    if choice2 == "h":
                        serial_arr[6].write(bytes(";" , 'ascii'))
                        serial_arr[6].write(bytes(str(choice3) , 'ascii'))
                        serial_arr[6].write(bytes("," , 'ascii'))
                        serial_arr[6].write(bytes(str(choice4) , 'ascii'))
                    if choice2 == "a":
                        serial_arr[7].write(bytes(";" , 'ascii'))
                        serial_arr[7].write(bytes(str(choice3) , 'ascii'))
                        serial_arr[7].write(bytes("," , 'ascii'))
                        serial_arr[7].write(bytes(str(choice4) , 'ascii'))
                print("Carl")
        except AttributeError:
            print("No servo attached")

        q = input("\nPress y or n to quit or not\n").capitalize()
        if q == "Y":
            return