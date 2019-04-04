import urllib.request
from bs4 import BeautifulSoup
url = 'https://baike.baidu.com/item/%E7%BD%91%E7%BB%9C%E7%88%AC%E8%99%AB/5162711'
response = urllib.request.urlopen(url)
html = response.read()
soup = BeautifulSoup(html,"html.parser")
