import os
from time import sleep
from selenium import webdriver
from webdriver_manager.chrome import ChromeDriverManager
 
# To auto-accept other people's post:
# step 0 : you need chrome for this. Also install modules :
# pip install selenium && pip install webdriver_manager && pip install tinydb
#step 2 : run code , check if you are logged in (if not, then login) then press 1 in console
#step 3 : the code shoud take care of the rest accept your new connection request in network tab

options = webdriver.ChromeOptions()
options.add_argument("user-data-dir={}\driver_data".format(os.getcwd()))
 
driver = webdriver.Chrome(ChromeDriverManager().install(), chrome_options=options)
 
driver.get("https://linkedin.com")

driver.get("https://www.linkedin.com/mynetwork/") 
sleep(4)
buttons = driver.find_elements_by_class_name("invitation-card__action-btn")

while "1" != input("press 1 when signed in: "):
    pass
for button in buttons:
    word=button.get_attribute("aria-label")
    if word.split(" ")[0] == "Accept":
        print("Clicking....")
        button.click()        
        print("Clicked!!")
        sleep(1)

print("Done")

driver.close()
