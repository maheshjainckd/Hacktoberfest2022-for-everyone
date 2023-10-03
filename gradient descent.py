import matplotlib.pyplot as plt
from math import floor
import numpy as np
def y(x):
    return x**2 + 5*x + 3
def grad(x):
    return  2*x + 5

x_cords = range(-5, 12)
y_cords = [y(x) for x in x_cords]

plt.plot(x_cords, y_cords)

x = 10
lr = 0.02

for i in range(0, 200):
    plt.plot([x], [y(x)], 'ro')
    plt.pause(0.1)

    x = x - (lr * grad(y(x)))
    print("Loss: ", x)
    
     
print("Global Minima at: " + str(round(x, 3)))
plt.show()
