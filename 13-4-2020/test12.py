# get content HTML
from bs4 import BeautifulSoup
import requests
url = requests.get("https://starbucks-dd9f6.web.app/#")
soup = BeautifulSoup(url.content, 'lxml')
text=soup.find_all(True,limit=1)
for i in text:
    print(i.text)