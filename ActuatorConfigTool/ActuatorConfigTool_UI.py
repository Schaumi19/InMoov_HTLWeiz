#author: Schaumi

import tkinter as tk
from tkinter import ttk
from time import sleep
import ActuatorConfigTool as actuator

root = tk.Tk()

actuator_values = [0, 0, 0, 0]

choices = ['Hüfte', 'Linke Schulter', 'Rechte Schulter']

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
        used_check = tk.Checkbutton(root, command=lambda i=i: disable(i))
        used_check.grid(row=i, column=1)
        root.used_checkboxes.append(used_check)
        increase_button = tk.Button(root, text="+", command=lambda i=i: moveActuator(i,1), state = "disabled")
        increase_button.grid(row=i, column=6)
        root.increase_buttons.append(increase_button)
        decrease_button = tk.Button(root, text="-", command=lambda i=i: moveActuator(i,0), state = "disabled")
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
    actuator.WriteConfig()

def LoadConfig():
    actuator.ReadConfig()
    sleep(1)
    root.cb.set(choices[actuator.pos])
    for i in range(4):
        root.actuator_minValues[i].config(text=actuator.motorData[i]["min_pot"])
        root.actuator_maxValues[i].config(text=actuator.motorData[i]["max_pot"])
        if actuator.motorData[i]["used"] == 1:
            root.used_checkboxes[i].select()
        else:
            root.used_checkboxes[i].deselect()

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
    actuator.SerialPrint(";" + str(i)+ "," + str(dir))
    
def TestDir(i):
    curPot = actuator_values[i]
    print(curPot)
    for j in range(10):
        actuator.SerialPrint(";" + str(i)+ "," + str(1))
        sleep(0.01)
    newPot = actuator.ReadNewPotValues()[i]
    if actuator.motorData[i]["reverse_input"] == 1:
        newPot = 1023 - newPot
    if newPot > curPot:
        print("Actuator",i,"is moving in the correct direction")
    else:
        actuator.motorData[i]["reverse_output"] = 1 - actuator.motorData[i]["reverse_output"]
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
    root.after(500, update_values)

def main():
    actuator.main()

    root.title("Actuator Config Tool")

    root.geometry("550x180")

    root.actuator_labels = []
    root.actuator_value_labels = []
    root.actuator_minValues = []
    root.actuator_maxValues = []

    root.dirTest_buttons = []
    root.used_checkboxes = []
    root.increase_buttons = []
    root.decrease_buttons = []
    root.setMin_buttons = []
    root.setMax_buttons = []
    root.rev_buttons = []

    create_widgets()

    for i in range(4):
        disable(i)

    root.after(100, update_values)
    root.mainloop()


if __name__ == "__main__":
    main()