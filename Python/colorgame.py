from tkinter import *
import random
from tkinter import messagebox

colors = ["Red", "Blue", "Pink", "Yellow", "Green", "Brown","Black", "Cyan", "White"]

score = 0
timeLeft = 30

def begin(event):
    if timeLeft == 30:
        countdown()
    
    nextColor()
     
def countdown():
    global timeLeft
    if timeLeft == 0:
        messagebox.showinfo("TIME OUT", "Time is over!!\nYour Score: " + str(score))
    if timeLeft > 0:
        timeLeft -= 1
        timeLabel.config(text = "Time Left: %s"%str(timeLeft))
        timeLabel.after(1000, countdown)
        
        
def nextColor():
    global score
    global timeLeft
    
    if timeLeft > 0:
        e.focus_set()
        if e.get().lower().strip() == colors[1].lower(): # Red == red, RED, rEd
            score += 1
            
        e.delete(0, END)
        random.shuffle(colors)
        
        label.config(bg = 'khaki', fg = str(colors[1]), text = str(colors[0]), padx = 15)
        
        scoreLabel.config(text = "Your Score: %s"%str(score))

def name():
#     e1.delete(0, END)
    x = e1.get()
    messagebox.showinfo("Welcome Message", " ☙ WELCOME TO CG Pro, " + x + " ☙")

    
# To clear the default text, when you click on the entry field
def clear_search(event):
    e1.delete(0, END)
  

root = Tk()
root.title("CG Pro")
# Width x Height
root.geometry("650x500")

# root.resizable(0, 0)
root.minsize(325, 400)
# root.maxsize(975, 450)


# to change color of entire window
root.configure(bg = "peach puff")


# ENTER PLAYER INFO
e1 = Entry(root, bd = 3, bg = 'linen', fg = 'coral', font = ("comic sans ms", 10, "italic"), relief = SUNKEN)
e1.insert(0, "Enter your Name here...")
e1.pack()
e1.bind("<Button-1>", clear_search)          # Vanish default text, once game is done


# Submit info button
frame = Frame(root, borderwidth = 4, bg = "red")
frame.pack()

button = Button(frame, fg = "yellow", bg = "green", text = "Enter Player Info", command = name, font = ("Comic sans ms", 10, 'bold'), activebackground = "pink", activeforeground = "black", height = 1)
button.pack()

# Instructions text
instructions = Label(root, text = '''*****INSTRUCTIONS*****
• A Text will be displayed in a specific color.
 • You have to print the COLOR of the text (Not the text itself)''', fg = 'brown', bg = "yellow", font = ("monotype corsiva", 16), padx = 20, pady = 20, 
                    borderwidth = 5, relief = RAISED)

instructions.pack(fill = X)

# Score Counter
scoreLabel = Label(root, text = "Press Enter to START", fg = 'magenta', bg = "pink", font = ("monotype corsiva", 20, 'bold'),padx = 20, borderwidth = 5, relief = RAISED)

scoreLabel.pack()

# Time left (TIMER)
timeLabel = Label(root, text = "Time Left: %s"%str(timeLeft),fg = 'blue', bg = "cyan", font = ("monotype corsiva", 18), borderwidth = 5, relief = RAISED)
 
timeLabel.pack(side = BOTTOM)


label = Label(root, text='', bg='peach puff', font = ("monotype corsiva", 60))

label.pack()


# Entry field for Answer
e = Entry(root, bd = 5, bg = 'linen', fg = 'coral', font = ("comic sans ms", 20, "italic"), relief = SUNKEN) # use font size, or use width = "any size"
e.insert(0, "Write here...")          # DEFAULT TEXT
root.bind('<Return>', begin)
e.pack()
e.focus_set()

root.mainloop()
