X = [0, -20, -40]


class Snake:
    from turtle import Turtle

    def __init__(self):
        self.turtles = []
        self.create_snake()

    def create_snake(self):
        for index in range(3):
            tim = self.Turtle("square")
            tim.penup()
            tim.color("white")
            tim.goto(x=X[index], y=0)
            self.turtles.append(tim)

    def reset(self):
        for turtle in self.turtles:
            turtle.goto(1000, 1000)
        self.turtles.clear()
        self.create_snake()

    def extend(self):
        tim = self.Turtle("square")
        tim.penup()
        tim.color("white")
        x_cor = self.turtles[-1].xcor()
        y_cor = self.turtles[-1].ycor()
        tim.goto(x=x_cor, y=y_cor)
        self.turtles.append(tim)

    def move(self):
        for index in range(len(self.turtles) - 1, 0, -1):
            x_cor = self.turtles[index - 1].xcor()
            y_cor = self.turtles[index - 1].ycor()
            self.turtles[index].goto(x_cor, y_cor)
        self.turtles[0].forward(20)

    def up(self):
        if self.turtles[0].heading() == 0:
            self.turtles[0].left(90)
        elif self.turtles[0].heading() == 180:
            self.turtles[0].right(90)

    def down(self):
        if self.turtles[0].heading() == 0:
            self.turtles[0].right(90)
        elif self.turtles[0].heading() == 180:
            self.turtles[0].left(90)

    def left(self):
        if self.turtles[0].heading() == 270:
            self.turtles[0].right(90)
        elif self.turtles[0].heading() == 90:
            self.turtles[0].left(90)

    def right(self):
        if self.turtles[0].heading() == 270:
            self.turtles[0].left(90)
        elif self.turtles[0].heading() == 90:
            self.turtles[0].right(90)
