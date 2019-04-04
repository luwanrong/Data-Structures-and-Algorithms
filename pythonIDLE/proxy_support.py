'''import urllib.request
import random

url = 'http://www.whatismyip.com.tw/'
print('添加代理ip')
iplist = input("开始输入：").split(sep = ";")
while True:

    ip = random.choice(iplist)
    proxy_support = urllib.request.ProxyHandler({'http':'ip'})
    #创建带有代理IP的opener
    opener = urllib.request.build_opener(proxy_support)
    #安装
    opener.addheaders = [('User-Agent','Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.139 Safari/537.36')]
    urllib.request.install_opener(opener)
    try:
        print("正在尝试访问%s" % ip)
        response = urllib.request.urlopen(url)
    except urllib.error.URLError:
        print('访问出错！')
    else:
        print('访问成功！')
    if input('请问是否继续？') == 'N':
        break
    #html = response.read().decode('utf-8')
    #print(html)
import urllib.request
import random

url = 'http://www.whatismyip.com.tw'
iplist = ['101.37.79.125']

proxy_support = urllib.request.ProxyHandler({'https':random.choice(iplist)})
opener = urllib.request.build_opener(proxy_support)
opener.addheaders = [('User-Agent','Test_Proxy_Python3.5_maminyao')]
urllib.request.install_opener(opener)
response = urllib.request.urlopen(url)
html = response.read().decode('utf-8')

print(html)'''
import urllib.request

proxy_support = urllib.request.ProxyHandler({'http': '106.56.102.96'})
opener = urllib.request.build_opener(proxy_support)

urllib.request.install_opener(opener)

a = urllib.request.urlopen("http://www.whatismyip.com.tw/").read().decode("utf-8")

print(a)

