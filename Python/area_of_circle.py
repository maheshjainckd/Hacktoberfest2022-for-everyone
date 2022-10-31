import math

diameter = input("Enter the diameter of the circle: ")
radius = int(diameter) // 2
area = math.pi * (radius * radius)

print(f"""
• Diameter: {diameter} ⌀
• Area of the Circle: {int(area)} cm
• Radius: {radius} R
""")
