import numpy as np
import matplotlib.pyplot as plt

#! install matplotlib, numpy using pip first


def Histogram():
    # setting up the figure size in inches
    plt.figure(figsize=(8, 8))

    # plotting the histogram data
    plt.hist([0, 0, 0, 5, 5, 9, 12, 12, 12, 12, 12, 16], bins=16, color="orange")
    #! bins = number of intervals in which you want to divide your data

    # setting the x-axis label with properties
    plt.xlabel(
        "Numbers", fontname="Times New Roman", fontsize=20, color="blue", weight="bold"
    )

    # setting the y-axis label with properties
    plt.ylabel(
        "Frequency",
        fontname="Times New Roman",
        fontsize=20,
        color="blue",
        weight="bold",
    )

    # creating a numpy array, [0-16]
    x = np.array([x for x in range(17)])

    # passing ticks of x axis, first argument is the position of ticks and second is the labels associates with ticks on x axis
    plt.xticks(x + 0.5, x)

    # setting the title of the graph
    plt.title(
        "Histogram", fontname="Times New Roman", fontsize=25, color="red", weight="bold"
    )

    # used to preview the plot
    plt.show()

    #! below commented line of code will save the graph in current working directory with 200dpi(dots per inch), increasing dpi will generate high quality images
    # plt.savefig("graph1.png", dpi=200)


def Boxplot():
    fig = plt.figure(figsize=(8, 8))

    # below two lines creates two subplots of the figure, ax1 and ax2
    ax1 = fig.add_subplot(2, 1, 1)
    ax2 = fig.add_subplot(2, 1, 2)
    # arguments: number of rows, number of cols, index
    #! if number of rows and number of columns both are greater than 2 then index will be a two digit tuple

    # giving supertitle (common title to both the plots)
    fig.suptitle("BoxPlot", fontname="Times New Roman", fontsize=24, color="orange")

    # adjusting the subplots
    fig.subplots_adjust(hspace=0.4)

    # plotting the boxplot data of plot 1 and 2
    ax1.boxplot([1, 2, 3, 4, 5, 6, 7], vert=False)
    ax2.boxplot(
        [1, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7], vert=False
    )

    # setting titles of both plots
    ax1.set_title("Symmetric", fontname="Times New Roman", fontsize=20, color="r")
    ax2.set_title("Left Skewed", fontname="Times New Roman", fontsize=20, color="b")

    # adding text inside plots
    #! dollar sign is used to conver the text to LaTex typesetting format (one of the best font)
    ax1.text(4, 0.8, "$Median$", fontsize=14, ha="center", va="center")
    ax2.text(4, 0.8, "$Median$", fontsize=14, ha="center", va="center")

    plt.show()
    # plt.savefig("graph3.png", dpi=200)


def PolynomialEquations():
    plt.figure(figsize=(8, 8))

    #! below code is used to center the axis of graph
    ax = plt.gca()
    ax.spines["top"].set_color("none")
    ax.spines["left"].set_position("zero")
    ax.spines["right"].set_color("none")
    ax.spines["bottom"].set_position("zero")

    #! linear equations
    # y = 2x + 12 in range [-8, -5)
    x = np.linspace(-8, -5, 600)  #! array of 600 equidistant points between -8 and -5
    plt.plot(x, 2 * x + 12, "r")

    # y = 2 in range [-5, 0)
    y = np.linspace(-5, -0, 1000)
    plt.plot(
        y, y - y + 2, "b"
    )  #! y - y + 2 is used to create array containing only 2 having same length as y

    # y = x + 1 in range [0, 3)
    z = np.linspace(0, 3, 600)
    plt.plot(z, z + 1, "c")

    # y = (-4/3)x + 8 in range (3, 6)
    w = np.linspace(3, 6, 600)
    plt.plot(w, (-4 / 3) * w + 8, "m")

    #! quadratic equation
    # y = (x - 20/3)^2 - 4/9 in range [6, 9)
    u = np.linspace(6, 9, 600)
    plt.plot(u, (u - (20 / 3)) ** 2 - (4 / 9), "g")

    # plotting closed markers, dark dots
    plt.plot(
        [-5, 0, 6, 3],
        [2, 1, 0, -2],
        marker=".",
        linestyle="",
        markeredgecolor="black",
        markersize=6,
        markerfacecolor="black",
    )

    # plotting open markers, hollow dots
    plt.plot(
        [0, 3],
        [2, 4],
        marker=".",
        linestyle="",
        markeredgecolor="black",
        markersize=8,
        markerfacecolor="white",
    )
    #! (3, -2) is a outside point in the graph

    # setting limits of x and y axis
    plt.axis(xmin=-8, xmax=8, ymin=-3, ymax=5)

    #! xticks and ytickc containing only label
    plt.xticks([x for x in range(-8, 10) if x != 0])
    plt.yticks([y for y in range(-4, 6) if y != 0 and y != 2])

    # title of the graph
    plt.title(
        "graph of g(x)",
        fontname="Times New Roman",
        fontsize=24,
        color="b",
        weight="bold",
        pad=20,
    )

    # adding coordinates text
    #! r is used to convert a string to raw string (escape charcaters are read as characters)
    plt.text(3, 4.2, r"(3,4)", fontsize=10, ha="center")
    plt.text(-5, 2.1, r"(-5,2)", fontsize=10, ha="center")
    plt.text(0.1, 1, r"(0,1)", fontsize=10, va="center")
    plt.text(3.1, -2, r"(3,-2)", fontsize=10, va="center")
    plt.text(-1.1, 2.2, r"(0,2)", fontsize=10, va="center")
    plt.text(6, 0.1, r"(6,0)", fontsize=10)
    plt.text(0.1, -0.3, r"0", fontsize=10)

    # adding expression text using LaTex typesetting
    plt.text(-3, 1.7, r"$y = 2$", ha="center", fontsize=11)
    plt.text(1.6, 2.6, r"$y = x + 1$", ha="center", rotation=58, fontsize=11)
    plt.text(-6.2, -2, r"$y = 2x + 12$", ha="center", rotation=72, fontsize=11)
    plt.text(
        4.6, 2, r"$y = -\frac{4}{3} x + 8$", ha="center", rotation=-67, fontsize=11
    )
    plt.text(
        8,
        2,
        r"$y = (x-\frac{20}{3})^2 - \frac{4}{9}$",
        ha="center",
        rotation=80,
        fontsize=11,
    )

    plt.show()
    # plt.savefig("graph4.png", dpi=200)


if __name__ == "__main__":
    #! if the source file is executed as the main program, interpreter sets __name__ = "__main__", if the file is being imported __name__ = "<module name>"
    Histogram()
    Boxplot()
    PolynomialEquations()
