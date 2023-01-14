from bs4 import BeautifulSoup
import requests 
import csv

url = "https://stackpython.co/"
req = requests.get(url)
# print(req)


# if req.status_code == 200:
#     print("succes")
# else:
#     print("not success")

# req.encoding = "utf-8"
soup = BeautifulSoup(req.text, "html.parser")
# print(soup.prettify()) # format

# courses = soup.find('title')  #Take the one that found first.
courses = soup.find_all('h2') # can limit ('h2', limit=2)
# print(courses)

# keep data
temp_list = []
course_list = []
for temp_course in courses:
    temp_list.append(temp_course.string) #get only string, not html

for courses in temp_list: # delete \n
    course_list.append(courses.replace("\n ", "")) 

print(temp_list)
print(course_list)

# print(course_list)


# csv_col = [["Column Name"],["data all values"]]
csv_col = [["Course Name"], [course_list]]
# print(csv_col)
f = open('stackpython-courses.csv', 'w',encoding = "utf-8")
with f:
    writer = csv.writer(f)  
    # print(writer)

    for row in csv_col:
        writer.writerow(row)