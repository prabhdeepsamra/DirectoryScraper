import requests
from bs4 import BeautifulSoup

file = open("testfile.txt","w")

letters = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
baseurl = "http://directory.ucmerced.edu/site/index/results/searchBy/lastName/searchFor/"

for i in range (0,26):
	for j in range(0,26):
		url=baseurl + letters[i]+letters[j]+"/"
		r=requests.get(url)
		soup = BeautifulSoup(r.content, "lxml")
		people = soup.find_all("li")
		for item in people:
			left=(item.find_all("div",{"class":"left"}))
			right= (item.find_all("div",{"class":"right"}))
			file.write(str(left))
			file.write(str(right))
			file.write("\n")
file.close()
