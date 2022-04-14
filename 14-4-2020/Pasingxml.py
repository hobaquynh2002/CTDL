from bs4 import BeautifulSoup
with open('test.xml', 'r') as f:
    file = f.read()
soup = BeautifulSoup(file, 'xml')

people=soup.find_all('people')
print(len(people))
x=[]
y=[]
for id in people:
    id=id.get('id')
    x.append(id)
for createAt in people:    
    createAt=createAt.get('createAt')
    y.append(createAt)
name = soup.find_all('name')
age= soup.find_all('age')
print('-'.center(45, '-'))
print('|' + 'id'.center(5) + '|' + 'name'.center(15) + '|' + 'age'.center(10) + '|' +'createAt'.center(10) + '|')
for i in range(0, len(name)):
    print('-'.center(45, '-'))
    print(f'|{x[i].center(5)}|{name[i].text.center(15)}|{age[i].text.center(10)}|{y[i].center(10)}|')
print('-'.center(45, '-'))