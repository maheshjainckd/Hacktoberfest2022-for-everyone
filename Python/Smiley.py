import arcade  # pip install arcade

# Setting size for main window
Window_width = 700
Window_height = 700

# Creating and opening the window
arcade.open_window(Window_width, Window_height, "Smiley")
arcade.set_background_color(arcade.color.BLACK)
arcade.start_render()  # Always use this before starting

# Base Structure
x = 350
y = 350
radius = 200
arcade.draw_circle_filled(x, y, radius, arcade.color.YELLOW)

# Right Eye
x = 420
y = 420
radius = 25
arcade.draw_circle_filled(x, y, radius, arcade.color.BLACK)

# Left Eye
x = 280
y = 420
radius = 25
arcade.draw_circle_filled(x, y, radius, arcade.color.BLACK)

# Curve
x = 340
y = 310
width = 120
height = 100
start_angle = 180
end_angle = 360
arcade.draw_arc_outline(
    x, y, width, height, arcade.color.BLACK, start_angle, end_angle, 10
)

arcade.finish_render()  # Ends the arcade
arcade.run()  # Keeps the window running until closed
