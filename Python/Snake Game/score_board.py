from turtle import Turtle

ALIGNMENT = "center"
FONT = ("Courier", 24, "normal")


class ScoreBoard(Turtle):
    def __init__(self):
        super().__init__()
        self.score = 0
        self.color("white")
        self.hideturtle()
        with open("high_score.txt") as file:
            self.high_score = int(file.read())
        self.penup()
        self.goto(0, 250)
        self.score_update()

    def score_update(self):
        self.clear()
        self.write(f"Score: {self.score} High Score: {self.high_score}", align=ALIGNMENT, font=FONT)

    def reset(self):
        if self.score > self.high_score:
            self.high_score = self.score
            with open("high_score.txt", mode="w") as file:
                file.write(f"{self.high_score}")
        self.score = 0
        self.score_update()

    def increase_score(self):
        self.score += 1
        self.score_update()


    # def game_over(self):
    #     self.goto(0,0)
    #     self.write("Game Over", align=ALIGNMENT, font=FONT)
