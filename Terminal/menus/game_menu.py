
import os
import RockPaperScissors as RPS


def games():
    os.system("clear")

    print("What game do you want to play? (enter quit to quit)\n")
    print("1. Rock Paper Scissors")

    choice = input()
    if choice == "quit":
        return
    elif choice == "1":
        RPS.rps()
