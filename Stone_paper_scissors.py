import tkinter
from tkinter.ttk import *
from tkinter import *
import pandas as pd
from PIL import ImageTk
import random
from PIL import Image
#paper=2,scissor=1,stone=3
individualscore,computerscore=0,0
computer=random.randint(1,4)
window = tkinter.Tk()
window.title("ston,paper,scissor")
label=tkinter.Label(window,text="its arth here!",font=("Arial Bold",50))
window.geometry('350x200')
label.grid(column=0,row=3)
for i in range (0,10):
 def Main():
  photo=Image.open(r'C:\Users\Arth Gupta\Desktop\photo\paper.jpg')  #replace this with paper image location of your choice
  photo=photo.resize((110,110))
  photo=ImageTk.PhotoImage(photo)
  bt=Button(window,image=photo,command=Paper)
  bt.grid(column=1,row=5)
  #################
  photo1=Image.open(r'C:\Users\Arth Gupta\Desktop\photo\stone.jpg')  #replace this with stone image location
  photo1=photo1.resize((110,110))
  photo1=ImageTk.PhotoImage(photo1)
  bt1=Button(window,image=photo1,command=Stone)
  bt1.grid(column=50,row=5)
  ##########3
  photo2=Image.open(r'C:\Users\Arth Gupta\Desktop\photo\scissor.jpg') #replace this with scissor image location
  photo2=photo2.resize((110,110))  
  photo2=ImageTk.PhotoImage(photo2)
  bt2=Button(window,image=photo2)
  bt2.grid(column=100,row=5)
  #window.mainloop
 def Paper():
   if computer>2:
          individualscore+=1
   elif computer<2:
          compoterscore+=2
   else:
          Main()
 def Stone():
   if computer==1:
         individualscore+=1
   elif computer==2:
         computerscore+=1
   else:
         Main()
 def Scissor():
   if computer==3:
         computerscore+=1
   elif computer==2:
         individualscore+=1
   else:
         Main()

 #'''def Main():
 #'''window.geometry('350x200')
# label.grid(column=0,row=3)

#def Clicked():
 #      print("heeelo")
  #     label.configure(text="you are amazing")

Main()
print(computerscore,individualscore)
window.mainloop
'''photo=Image.open(r'C:\Users\Arth Gupta\Desktop\photo\paper.jpg')
 photo=photo.resize((110,110))
 photo=ImageTk.PhotoImage(photo)
 bt=Button(window,image=photo)
 bt.grid(column=1,row=4)
 #################
 photo1=Image.open(r'C:\Users\Arth Gupta\Desktop\photo\stone.jpg')
 photo1=photo1.resize((110,110))
 photo1=ImageTk.PhotoImage(photo1)
 bt1=Button(window,image=photo1)
 bt1.grid(column=4,row=4)
 ##########3
 photo2=Image.open(r'C:\Users\Arth Gupta\Desktop\photo\scissor.jpg')
 photo2=photo2.resize((110,110))
 photo2=ImageTk.PhotoImage(photo2)
 bt2=Button(window,image=photo2)
 bt2.grid(column=7,row=4)
 #window.mainloop
Main()
photon=Image.open(r'C:\Users\Arth Gupta\Desktop\photo\play.jpg')
photon=photon.resize((410,410))
photon=ImageTk.PhotoImage(photon)
btn=Button(window,image=photon,command=Main)
btn.grid(column=4,row=4)'''

