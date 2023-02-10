import tkinter as tk
import ActuatorConfigTool as actuator

root = tk.Tk()


actuator_minValues = [0,0,0,0]
actuator_maxValues = [0,0,0,0]
actuator_values = [0, 0, 0, 0]
rev = [0,0,0,0]
used = [0,0,0,0]

def create_widgets():
    global actuator_minValues
    global actuator_maxValues
    global actuator_values
    global used

    # Create labels to display current actuator values
    
    for i in range(4):
        label = tk.Label(root, text="Actuator {}: ".format(i+1))
        label.grid(row=i, column=2)
        root.actuator_labels.append(label)
        label = tk.Label(root, text=actuator_minValues[i])
        label.grid(row=i, column=3)
        root.actuator_minValues.append(label)
        label = tk.Label(root, text=actuator_values[i])
        label.grid(row=i, column=4)
        root.actuator_value_labels.append(label)
        label = tk.Label(root, text=actuator_maxValues[i])
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
        Rev_button = tk.Button(root, text="Rev", command=lambda i=i: Rev(i))
        Rev_button.grid(row=i, column=11)
        root.rev_buttons.append(Rev_button)

def disable(i):
    global used
    if(used[i] == 1):
        used[i] = 0
        root.actuator_labels[i].config(state = "disabled")
        root.actuator_value_labels[i].config(state = "disabled")
        root.actuator_minValues[i].config(state = "disabled")
        root.actuator_maxValues[i].config(state = "disabled")
        root.dirTest_buttons[i].config(state = "disabled")
        root.increase_buttons[i].config(state = "disabled")
        root.decrease_buttons[i].config(state = "disabled")
        root.setMin_buttons[i].config(state = "disabled")
        root.setMax_buttons[i].config(state = "disabled")
        root.rev_buttons[i].config(state = "disabled")
    else:
        used[i] = 1
        root.actuator_labels[i].config(state = "active")
        root.actuator_value_labels[i].config(state = "active")
        root.actuator_minValues[i].config(state = "active")
        root.actuator_maxValues[i].config(state = "active")
        root.dirTest_buttons[i].config(state = "active")
        root.setMin_buttons[i].config(state = "active")
        root.setMax_buttons[i].config(state = "active")
        root.rev_buttons[i].config(state = "active")


def moveActuator( i, dir):
    global actuator_values
    actuator_values[i] += 1
    
def TestDir(i):
    root.decrease_buttons[i].config(state = "active")
    root.increase_buttons[i].config(state = "active")

def SetMin(i):
    global actuator_minValues
    global actuator_values
    actuator_minValues[i] = actuator_values[i]
    root.actuator_minValues[i].config(text=actuator_minValues[i])

def SetMax(i):
    global actuator_maxValues
    global actuator_values
    actuator_maxValues[i] = actuator_values[i]
    root.actuator_maxValues[i].config(text=actuator_maxValues[i])

def Rev(i):
    global rev
    if(rev[i] == 0):
        rev[i] = 1
    else:
        rev[i] = 0
    print("Rev",i)
    
def update_values():
    global rev
    global actuator_values
    actuator_values = actuator.ReadNewPotValues()
    for i in range(4):
        if rev[i] == 1:
            actuator_values[i] = 1024 - actuator_values[i]
        root.actuator_value_labels[i].config(text=actuator_values[i])
    root.after(500, update_values)

def main():

    actuator.main()

    root.title("Actuator Controls")

    root.geometry("500x200")

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