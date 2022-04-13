#get content XML
from bs4 import BeautifulSoup
import requests
with open('file1.xml', 'r') as f:
    f=f.read()
soup = BeautifulSoup(f.content, 'lxml')
text=soup.find_all(True,limit=1)
for i in text:
    print(i.text)
