from bs4 import BeautifulSoup
data = open("emoji_list.html","r").read()

soup = BeautifulSoup(data)
anchors = soup.findAll('a')
for anchor in anchors:
    anchor.replaceWithChildren()


print(soup)