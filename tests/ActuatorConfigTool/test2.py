from tkinter import * 
running = False
root = Tk()
def start_motor(event,time):
    global running
    running = True
    print(f"starting motor...{time}")

def stop_motor(event):
    global running
    print("stopping motor...")
    running = False

button = Button(root, text ="forward")
button.pack(side=LEFT)
button.bind('<ButtonPress-1>',lambda eff: start_motor(eff,5))
button.bind('<ButtonRelease-1>',stop_motor)
root.mainloop()