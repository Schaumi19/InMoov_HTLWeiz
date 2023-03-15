#author: Schaumi

import tkinter as tk
from tkinter import ttk
from time import sleep
import ActuatorConfigTool as actuator

root = tk.Tk()

actuator_values = [0, 0, 0, 0]

choices = ['Hüfte', 'Linke Schulter', 'Rechte Schulter']

move = False

def create_widgets():
    # Create labels to display current actuator values
    
    for i in range(4):
        label = tk.Label(root, text="Actuator {}: ".format(i+1))
        label.grid(row=i, column=2)
        root.actuator_labels.append(label)
        label = tk.Label(root, text=actuator.motorData[i]["min_pot"])
        label.grid(row=i, column=3)
        root.actuator_minValues.append(label)
        label = tk.Label(root, text=actuator_values[i])
        label.grid(row=i, column=4)
        root.actuator_value_labels.append(label)
        label = tk.Label(root, text=actuator.motorData[i]["max_pot"])
        label.grid(row=i, column=5)
        root.actuator_maxValues.append(label)
    # Create buttons to increase/decrease actuator values

    for i in range(4):
        used_check = tk.Checkbutton(root, command=lambda i=i: disable(i), variable=root.useds[i])
        used_check.grid(row=i, column=1)
        root.used_checkboxes.append(used_check)
        increase_button = tk.Button(root, text="+")
        increase_button.bind("<ButtonPress>", lambda _,i=i: moveActuator(i,1))
        increase_button.bind("<ButtonRelease>", lambda _,i=i: stopActuator(i))
        increase_button.grid(row=i, column=6)
        root.increase_buttons.append(increase_button)
        decrease_button = tk.Button(root, text="-")
        decrease_button.bind("<ButtonPress>", lambda _,i=i: moveActuator(i,0))
        decrease_button.bind("<ButtonRelease>", lambda _,i=i: stopActuator(i))
        decrease_button.grid(row=i, column=7)
        root.decrease_buttons.append(decrease_button)
        dirTest_button = tk.Button(root, text="Direction Test", command=lambda i=i: TestDir(i))
        dirTest_button.grid(row=i, column=8)
        root.dirTest_buttons.append(dirTest_button)
        SetMin_button = tk.Button(root, text="Set Min", command=lambda i=i: SetMin(i))
        SetMin_button.grid(row=i, column=9)
        root.setMin_buttons.append(SetMin_button)
        SetMax_button = tk.Button(root, text="Set Max", command=lambda i=i: SetMax(i))
        SetMax_button.grid(row=i, column=10)
        root.setMax_buttons.append(SetMax_button)
        Rev_button = tk.Button(root, text="Rev", command=lambda i=i: Reverse(i))
        Rev_button.grid(row=i, column=11)
        root.rev_buttons.append(Rev_button)

        label = tk.Label(root, text="Use Angular Speed: ")
        label.grid(row=i, column=12)
        useAngularSpeed = tk.Checkbutton(root, variable=root.useAngularSpeeds[i])
        useAngularSpeed.grid(row=i, column=13)
        root.useAngularSpeed_checkboxes.append(useAngularSpeed)

        label = tk.Label(root, text="Max Speed: ")
        label.grid(row=i, column=14)
        input = tk.Entry(root, width=3)
        input.insert(0, "255")
        input.grid(row=i, column=15)
        root.maxSpeeds.append(input)

        label = tk.Label(root, text="goalDeadzone: ")
        label.grid(row=i, column=16)
        input = tk.Entry(root, width=3)
        input.insert(0, "5")
        input.grid(row=i, column=17)
        root.goalDeadzones.append(input)

        label = tk.Label(root, text="Continuous Movement: ")
        label.grid(row=i, column=18)
        input = tk.Entry(root, width=3)
        input.insert(0, "0")
        input.grid(row=i, column=19)
        root.continuousMovements.append(input)

        label = tk.Label(root, text="ErrorMinDiff: ")
        label.grid(row=i, column=20)
        input = tk.Entry(root, width=3)
        input.insert(0, "5")
        input.grid(row=i, column=21)
        root.errorMinDiffs.append(input)

        label = tk.Label(root, text="ErrorMinAngularSpeed: ")
        label.grid(row=i, column=22)
        input = tk.Entry(root, width=3)
        input.insert(0, "5")
        input.grid(row=i, column=23)
        root.errorMinAngularSpeeds.append(input)

    for i in range(4):
        disable(i)

    # Position Selection Box
    choiceVar = tk.StringVar()
    choiceVar.set(choices[0])
    cb = ttk.Combobox(root, textvariable=choiceVar, values=choices)
    cb_Label = tk.Label(root, text="Position: ")
    cb_Label.grid(row=4, column=1, columnspan=2)
    cb.grid(row=4, column=3, columnspan=3)
    root.cb = cb
    
    # Create button to load and save actuator values
    load_button = tk.Button(root, text="Load", command=LoadConfig)
    load_button.grid(row=5, column=1)
    save_button = tk.Button(root, text="Save", command=SaveConfig)
    save_button.grid(row=5, column=2)

def SaveConfig():
    pos = root.cb.get()
    if pos == "Hüfte":
        actuator.pos = 0
    elif pos == "Linke Schulter":
        actuator.pos = 1
    elif pos == "Rechte Schulter":
        actuator.pos = 2

    for i in range(4):
        actuator.motorData[i]["used"] = root.useds[i].get()
        actuator.motorData[i]["useAngularSpeed"] = root.useAngularSpeeds[i].get()

        actuator.motorData[i]["maxSpeed"] = int(root.maxSpeeds[i].get())
        actuator.motorData[i]["goalDeadzone"] = int(root.goalDeadzones[i].get())
        actuator.motorData[i]["continuousMovement"] = int(root.continuousMovements[i].get())
        actuator.motorData[i]["errorMinDiff"] = int(root.errorMinDiffs[i].get())
        actuator.motorData[i]["errorMinAngularSpeed"] = int(root.errorMinAngularSpeeds[i].get())
    actuator.WriteConfig()

def LoadConfig():
    actuator.ReadConfig()
    print("Actuator Position:"+str(actuator.pos))
    root.cb.set(choices[actuator.pos])
    for i in range(4):
        root.actuator_minValues[i].config(text=actuator.motorData[i]["min_pot"])
        root.actuator_maxValues[i].config(text=actuator.motorData[i]["max_pot"])
        if actuator.motorData[i]["used"] == 1:
            root.used_checkboxes[i].select()
        else:
            root.used_checkboxes[i].deselect()
        if actuator.motorData[i]["useAngularSpeed"] == 1:
            root.useAngularSpeed_checkboxes[i].select()
        else:
            root.useAngularSpeed_checkboxes[i].deselect()
        root.maxSpeeds[i].delete(0, tk.END)
        root.maxSpeeds[i].insert(0, actuator.motorData[i]["maxSpeed"])
        root.goalDeadzones[i].delete(0, tk.END)
        root.goalDeadzones[i].insert(0, actuator.motorData[i]["goalDeadzone"])
        root.continuousMovements[i].delete(0, tk.END)
        root.continuousMovements[i].insert(0, actuator.motorData[i]["continuousMovement"])
        root.errorMinDiffs[i].delete(0, tk.END)
        root.errorMinDiffs[i].insert(0, actuator.motorData[i]["errorMinDiff"])
        root.errorMinAngularSpeeds[i].delete(0, tk.END)
        root.errorMinAngularSpeeds[i].insert(0, actuator.motorData[i]["errorMinAngularSpeed"])
    

        if(actuator.motorData[i]["used"] == 0):
            root.actuator_labels[i].config(state = "disabled")
            root.dirTest_buttons[i].config(state = "disabled")
            root.increase_buttons[i].config(state = "disabled")
            root.decrease_buttons[i].config(state = "disabled")
            root.setMin_buttons[i].config(state = "disabled")
            root.setMax_buttons[i].config(state = "disabled")
            root.rev_buttons[i].config(state = "disabled")
        else:
            root.actuator_labels[i].config(state = "active")
            root.actuator_value_labels[i].config(state = "active")
            root.actuator_minValues[i].config(state = "active")
            root.actuator_maxValues[i].config(state = "active")
            root.dirTest_buttons[i].config(state = "active")
        

def disable(i):
    if(actuator.motorData[i]["used"] == 1):
        actuator.motorData[i]["used"] = 0
        root.actuator_labels[i].config(state = "disabled")
        root.dirTest_buttons[i].config(state = "disabled")
        root.increase_buttons[i].config(state = "disabled")
        root.decrease_buttons[i].config(state = "disabled")
        root.setMin_buttons[i].config(state = "disabled")
        root.setMax_buttons[i].config(state = "disabled")
        root.rev_buttons[i].config(state = "disabled")
    else:
        actuator.motorData[i]["used"] = 1
        root.actuator_labels[i].config(state = "active")
        root.actuator_value_labels[i].config(state = "active")
        root.actuator_minValues[i].config(state = "active")
        root.actuator_maxValues[i].config(state = "active")
        root.dirTest_buttons[i].config(state = "active")
        


def moveActuator( i, dir):
    global move
    move = True
    print("moveActuator")
    if(actuator.motorData[i]["reverse_output"] == 1):
        dir = 1 - dir
    reallyMoveActuator(i,dir)

def reallyMoveActuator(i,dir):
    if move:
        print("reallyMoveActuator")
        actuator.SerialPrint(";" + str(i)+ "," + str(dir))
        root.after(100,reallyMoveActuator,i,dir)

def stopActuator(i):
    print("stopActuator")
    global move
    move = False
    
def TestDir(i):
    """Test if the actuator is moving in the correct direction"""
    print("TestDir")
    curPot = actuator_values[i]
    print(curPot)
    for j in range(5):
        actuator.SerialPrint(";" + str(i)+ "," + str(1))
        sleep(0.1)
    sleep(1.5)
    for x in range(5):
        newPot = actuator.ReadNewPotValues()[i]
    if newPot > curPot:
        print("Actuator",i,"is moving in the correct direction")
        actuator.motorData[i]["reverse_output"] = 0
    else:
        actuator.motorData[i]["reverse_output"] = 1
        print("Actuator",i,"is moving in the wrong direction")

    
    root.decrease_buttons[i].config(state = "active")
    root.increase_buttons[i].config(state = "active")
    root.setMin_buttons[i].config(state = "active")
    root.setMax_buttons[i].config(state = "active")
    root.rev_buttons[i].config(state = "active")

def SetMin(i):
    actuator.motorData[i]["min_pot"] = actuator_values[i]
    root.actuator_minValues[i].config(text=actuator.motorData[i]["min_pot"])

def SetMax(i):
    actuator.motorData[i]["max_pot"] = actuator_values[i]
    root.actuator_maxValues[i].config(text=actuator.motorData[i]["max_pot"])

def Reverse(i):
    actuator.motorData[i]["reverse_input"] = 1 - actuator.motorData[i]["reverse_input"]
    actuator.motorData[i]["reverse_output"] = 1 - actuator.motorData[i]["reverse_output"]
    
def update_values():
    global actuator_values
    actuator_values = actuator.ReadNewPotValues()
    for i in range(4):
        if actuator.motorData[i]["reverse_input"] == 1:
            actuator_values[i] = 1023 - actuator_values[i]
        root.actuator_value_labels[i].config(text=actuator_values[i])
    root.after(800, update_values)

def main():
    actuator.main()

    root.title("Actuator Config Tool")

    root.geometry("1300x180")

    root.actuator_labels = []
    root.actuator_value_labels = []
    root.actuator_minValues = []
    root.actuator_maxValues = []

    root.dirTest_buttons = []
    root.used_checkboxes = []
    root.useds = []
    for i in range(4):
        root.useds.append(tk.IntVar())
    root.increase_buttons = []
    root.decrease_buttons = []
    root.setMin_buttons = []
    root.setMax_buttons = []
    root.rev_buttons = []

    root.useAngularSpeed_checkboxes = []
    root.useAngularSpeeds = []
    for i in range(4):
        root.useAngularSpeeds.append(tk.IntVar())

    root.continuousMovements = []
    root.goalDeadzones = []
    root.maxSpeeds = []
    root.errorMinDiffs = []
    root.errorMinAngularSpeeds = []

    create_widgets()

    for i in range(4):
        disable(i)

    root.after(100, update_values)
    root.mainloop()


if __name__ == "__main__":
    main()