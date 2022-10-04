import sys
import os
import webbrowser
import pyautogui
import time
path = "/home/codemap/Documents/Projects/"

print('This thing works only when SSH setup has been established.')

folderName = input("Enter you project's name: ")
if folderName == "":
	while True:
		folderName = input("Enter you project's name: ")
		if folderName == "":
			print('Enter a value!')
			pass
		else:
			break
username = input('Enter your github username: ')
if username == "":
	while True:
		username = input("Enter you username: ")
		if username == "":
			print('Enter a value!')
			pass
		else:
			break
webbrowser.open('https://github.com/new')
time.sleep(10)
pyautogui.click(x=930, y=495)
pyautogui.write(folderName)
time.sleep(5)
pyautogui.scroll(-1000)
pyautogui.click(x=690,y=905)
time.sleep(5)
pyautogui.hotkey('ctrl','alt','t')
time.sleep(3)
pyautogui.write(f'cd {path}')
pyautogui.press('enter')
pyautogui.write(f'git clone git@github.com:{username}/{folderName}.git')
pyautogui.press('enter')

print(f"Succesfully created repository {folderName}")

