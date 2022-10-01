Importing tkinter module

2

from tkinter import *

3

#importing calendar module

4

import calendar

5



6

#function to show calendar of the given year

7

def showCalender():

8

    gui = Tk()

9

    gui.config(background='grey')

10

    gui.title("Calender for the year")

11

    gui.geometry("550x600")

12

    year = int(year_field.get())

13

    gui_content= calendar.calendar(year)

14

    calYear = Label(gui, text= gui_content, font= "Consolas 10 bold")

15

    calYear.grid(row=5, column=1,padx=20)

16

    gui.mainloop()

1

#Driver code

2

if __name__=='__main__':

3

    new = Tk()

4

    new.config(background='grey')

5

    new.title("Calender")

6

    new.geometry("250x140")

7

    cal = Label(new, text="Calender",bg='grey',font=("times", 28, "bold"))

8

    year = Label(new, text="Enter year", bg='dark grey')

9

    year_field=Entry(new)

10

    button = Button(new, text='Show Calender',

11

fg='Black',bg='Blue',command=showCalender)

12



13

    #putting widgets in position

14

    cal.grid(row=1, column=1)

15

    year.grid(row=2, column=1)

16

    year_field.grid(row=3, column=1)

17

    button.grid(row=4, column=1)

18

    Exit.grid(row=6, column=1)

19

    new.mainloop()

20

