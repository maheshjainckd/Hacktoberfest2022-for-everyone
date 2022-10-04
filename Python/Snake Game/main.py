import time
from turtle import Screen
from snake import Snake
from food import Food
from score_board import ScoreBoard

screen = Screen()
screen.setup(width=600, height=600)
screen.bgcolor("black")
screen.title("My Snake Game")
screen.tracer(0)

snake = Snake()
food = Food()
score_board = ScoreBoard()

screen.listen()
screen.onkey(snake.up, "Up")
screen.onkey(snake.down, "Down")
screen.onkey(snake.left, "Left")
screen.onkey(snake.right, "Right")

game_start = True
while game_start:

    screen.update()
    time.sleep(0.1)
    snake.move()

    # detect collision with food
    if snake.turtles[0].distance(food) < 15:
        snake.extend()
        food.refresh()
        score_board.increase_score()

    # detect collision with walls
    if snake.turtles[0].xcor() > 280 or snake.turtles[0].xcor() < -280 or snake.turtles[0].ycor() > 280 or \
            snake.turtles[0].ycor() < -280:
        score_board.reset()
        snake.reset()
        screen.update()

    # detect collision with tail.
    for segment in snake.turtles[1:]:
        if snake.turtles[0].distance(segment) < 18:
            score_board.reset()
            snake.reset()
            screen.update()

screen.exitonclick()
