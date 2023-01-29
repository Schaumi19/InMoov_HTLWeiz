import tkinter as tk


def create_widgets():
    # Create labels to display current actuator values
    
    for i in range(4):
        label = tk.Label(root, text="Actuator {}: ".format(i+1))
        label.grid(row=i, column=0)
        root.actuator_labels.append(label)
        label = tk.Label(root, text=actuator_minValues[i])
        label.grid(row=i, column=1)
        root.actuator_minValues.append(label)
        label = tk.Label(root, text=actuator_values[i])
        label.grid(row=i, column=2)
        root.actuator_values.append(label)
        label = tk.Label(root, text=actuator_maxValues[i])
        label.grid(row=i, column=3)
        root.actuator_maxValues.append(label)
    # Create buttons to increase/decrease actuator values
    
    root.dirTest_buttons = []
    for i in range(4):
        increase_button = tk.Button(root, text="+", command=lambda i=i: moveActuator(i,1), state = "disabled")
        increase_button.grid(row=i, column=4)
        root.increase_buttons.append(increase_button)
        decrease_button = tk.Button(root, text="-", command=lambda i=i: moveActuator(i,0), state = "disabled")
        decrease_button.grid(row=i, column=5)
        root.decrease_buttons.append(decrease_button)
        dirTest_button = tk.Button(root, text="Direction Test", command=lambda i=i: TestDir(i))
        dirTest_button.grid(row=i, column=6)
        root.dirTest_buttons.append(dirTest_button)



def moveActuator( i, dir):
    actuator_values[i] += 1
    
def TestDir(i):
    root.decrease_buttons[i].config(state = "active")
    root.increase_buttons[i].config(state = "active")
    
def update_values():
    for i in range(4):
        root.actuator_values[i].config(text=actuator_values[i])
    root.after(100, update_values)


if __name__ == "__main__":
    root = tk.Tk()

    root.title("Actuator Controls")

    root.geometry("500x200")

    actuator_values = [0, 0, 0, 0]
    actuator_minValues = [0,0,0,0]
    actuator_maxValues = [0,0,0,0]

    root.actuator_labels = []
    root.actuator_values = []
    root.actuator_minValues = []
    root.actuator_maxValues = []

    root.increase_buttons = []
    root.decrease_buttons = []

    create_widgets()

    root.after(100, update_values)
    root.mainloop()
