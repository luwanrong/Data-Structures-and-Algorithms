import requests
from bs4 import BeautifulSoup
headers = {
    'User-Agent':'Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/67.0.3396.99 Safari/537.36'
    
}
url = 'https://legalref.judiciary.hk/lrs/common/ju/judgment.jsp?L1=FA#H1'
resp = requests.get(url,headers = headers)
soup = BeautifulSoup(resp.text,'lxml')
print(soup.a)
