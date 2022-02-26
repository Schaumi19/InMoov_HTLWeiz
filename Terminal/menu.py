# -- Global imports -- #


import os



# -- Global script -- #


def main_menu():
    """This is the main menu of the InMoov terminal
    """

    while(True):
        choice = main_choice()

        if choice == 1:
            monitoring()
        elif choice == 2:
            steering()
        elif choice == 3:
            gestures()
        elif choice == 4:
            voice_lines()


def main_choice():
    os.system("clear")
    print("\nWhich action would you like to perform?\n\n")
    print("1: monitoring of servo values")
    print("2: steering of servos")
    print("3: show/create a gesture (coming soon)")
    print("4: voice lines (comint soon)\n")

    choice = int(input())
    while choice != 1 and choice != 2 and choice != 3 and choice != 4:
        print("Please enter again")
        choice = int(input())
    return choice


def monitoring():
    os.system("clear")


def steering():
    os.system("clear")


def gestures():
    os.system("clear")


def voice_lines():
    os.system("clear")
