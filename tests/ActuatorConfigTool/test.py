import tkinter as tk


def create_widgets():
    # Create labels to display current actuator values
    
    for i in range(4):
        label = tk.Label(root, text="Actuator {}: {}".format(i+1, actuator_values[i]))
        label.grid(row=i, column=0)
        root.actuator_labels.append(label)
    # Create buttons to increase/decrease actuator values
    root.increase_buttons = []
    root.decrease_buttons = []
    for i in range(4):
        increase_button = tk.Button(root, text="+", command=lambda i=i: moveActuator(i,1))
        increase_button.grid(row=i, column=1)
        root.increase_buttons.append(increase_button)
        decrease_button = tk.Button(root, text="-", command=lambda i=i: moveActuator(i,0))
        decrease_button.grid(row=i, column=2)
        root.decrease_buttons.append(decrease_button)
def moveActuator( i, dir):
    actuator_values[i] += 1
    update_labels()
def update_labels():
    for i in range(4):
        root.actuator_labels[i].config(text="Actuator {}: {}".format(i+1, actuator_values[i]))


if __name__ == "__main__":
    root = tk.Tk()

    root.title("Actuator Controls")
    actuator_values = [0, 0, 0, 0]
    actuator_minValues = [0,0,0,0]
    actuator_maxValues = [0,0,0,0]

    root.actuator_labels = []

    create_widgets()

    root.after(1000, update_labels)
    root.mainloop()
