import tkinter as tk

baudrate = 115200
serial_port = None


#Aktuator Values
CurrentInput = [0,0,0,0]
MinInput = [0,0,0,0]
MaxInput = [0,0,0,0]



def main():

    root = tk.Tk()

    root.title = "ActuatorConfigTool"

    label = tk.Label(root, text="ActuatorConfigTool", font=('Times', 24))
    label.pack()

    checkbox = tk.Checkbutton(root)
    checkbox.pack()

    for i in range(4):
        label = tk.Label( text=f"Actuator{i}:", font=('Times', 12))
        label.grid(row=0, column=0, padx='5', pady='5', sticky='ew')
        #label.pack()
    

    button = tk.Button(root, text="Raub", command=main)
    button.pack()

    button = tk.Button(root, text="Quit", command=root.quit)
    button.pack()

    root.mainloop()
"""
    global serial_port
    serial_arr = ports.setup_ports(baudrate)
    serial_port = serial_arr[0]
    serial_port.open()
    print(serial_port)
"""


if __name__ == "__main__":
    main()




