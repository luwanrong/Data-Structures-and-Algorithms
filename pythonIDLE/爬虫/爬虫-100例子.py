from bs4 import BeautifulSoup
import requests

'''
获取url
1.python100的url
2.每一个练习题的url
'''
#请求url
url = 'http://www.runoob.com/python/python-100-examples.html'
headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/67.0.3396.99 Safari/537.36'
    }
r = requests.get(url,headers = headers).content.decode('utf-8')
#print(type(r))#‘r’为字符串类型
#解析html文档

html = BeautifulSoup(r,'lxml')
#print(type(html))  # r 被解析为BeautifulSoup类型

#查找练习题的链接地址

#在‘ul’标签下，包含有‘li’标签，每一个‘li’标签包含 一个‘a’对应每一个练习
#print(html.find(id="content").li.find_all('a'))
re_a = html.find(id="content").ul.find_all('a') #返回一个列表
#遍历列表，读出每一个元素
lis = []
for i in re_a:
    lis.append('http://www.runoob.com'+i.attrs['href'])
#print(lis[1])
datas = []
dic = {}
for x in lis:
    #请求练习的url  并解析
    ar = requests.get(x,headers = headers).content.decode('utf-8')
    html1 = BeautifulSoup(ar,'lxml')
    #print(html1)

    dic['title'] = html1.find(id="content").h1.text
    #print(title)

    dic['tm']= html1.find(id="content").find_all('p')[1].text
    #print(tm)

    dic['cxfx'] = html1.find(id="content").find_all('p')[2].text

    try:
        dic['code'] = html1.find(class_="hl-main").text
    except Exception as e:
        dic['code'] = html1.find('pre').text
    #print(dic)
    #datas.append(dic)

    with open('py100.csv','a+',encoding = 'utf-8') as file:
        file.write(dic['title']+'\n')
        file.write(dic['tm']+'\n')
        file.write(dic['cxfx']+'\n')
        file.write(dic['code']+'\n')
        file.write('*'*50+'\n')
#import pandas as pd
#data = pd.DataFrame(datas)
#data.to_csv('py100.csv')

