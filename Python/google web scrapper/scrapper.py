import requests
from bs4 import BeautifulSoup
import re

keywords = {
    "php",
    "mysql",
    "database",
    "restapi",
    "restfullapi",
    "encryption",
    "pentest",
    "hacking",
}

for keyword in keywords:
    for page in range(1, 10):
        pages = requests.get("https://www.google.com/search?q=" + keyword + "&start=" + str(page * 10))
        soup = BeautifulSoup(pages.content)
        links = soup.findAll("a")
        for link in soup.find_all("a",href=re.compile("(?<=/url\?q=)(htt.*://.*)")):
            print(re.split(":(?=http)",link["href"].replace("/url?q=","")))
            with open("result.txt", "a") as f:
                f.write(link["href"].replace("/url?q=","") + "\n")