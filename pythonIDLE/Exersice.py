#迭代器
#it = iter('FishC') #得到迭代器，对一个容器对象调用
#或者
'''string = 'FishC'
it = iter(string)

class Fibs:
    def __init__(self,n=20):
        self.a = 0;
        self.b = 1;
        self.n = n
    def __iter__(self):
        return self
    def __next__(self):
        self.a, self.b= self.b,self.a + self.b
        if self.a > self.n:
            raise StopIteration
        else:
            return self.a

def c2f(cel):
    fah = cel * 1.8 + 32
    return fah
def f2c(fah):
    cel = (fah - 32)/1.8
    return cel
def text():
    print('测试，0摄氏度 = %.2f华氏度' % c2f(0))
    print('测试，0华氏度 = %.2f摄氏度' % f2c(0))
if __name__ == '__main__':
    text()
import urllib.request
import urllib.parse
import json

content = input('请输入与要翻译的内容：')
#url = "http://fanyi.youdao.com/translate_o?smartresult=dict&smartresult\
#=rule&smartresult=ugc&sessionFrom=http://www.youdao.com/"
url = "http://fanyi.youdao.com/translate?smartresult=dict&smartresult=ugc"
data = {}
data['type'] = 'AUTO'
data['i'] = content
data['doctype'] = 'json'
data['xmlVersion'] = '1.6'
data['keyfrom'] = 'fanyi.web'
data['ue'] = 'UTF-8'
data['typoResult'] = 'ture'
data = urllib.parse.urlencode(data).encode('utf-8')
response = urllib.request.urlopen(url,data)
html = response.read().decode('utf-8')
target = json.loads(html)
print("翻译结果: %s" % (target['translateResult'][0][0]['tgt']))
#print(html)'''
import urllib.request

import urllib.parse
import json


content = input("请输入要翻译的内容:")
url = "http://fanyi.youdao.com/translate?smartresult=dict&smartresult=ugc"
#url = "http://fanyi.youdao.com/translate_o?smartresult=dict&smartresult=rule"
head = {}
head['Referer'] = 'http://fanyi.youdao.com'
head['User-Agent'] = 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.139 Safari/537.36'
data = {}
data['i'] = content
data['from'] = 'AUTO'#从浏览器复制
data['to']='AUTO'
data['smartresult']='dict'
data['client']='fanyideskweb'
data['salt']='1513663501217'
data['sign']='6a516734349a812792c07491f639609e'
data['doctype'] = 'json'
data['version'] = '2.1'
data['keyfrom']='fanyi.web'
data['action']='FY_BY_REALTIME'
data['typoResult']='false'
data = urllib.parse.urlencode(data).encode('utf-8')#把data转化为application/x-www-form-urlencode格式，使用utf-8编码
req = urllib.request.Request(url,data,head)
response = urllib.request.urlopen(req)
html = response.read().decode('utf-8')
target = json.loads(html)
print("result: %s" % (target['translateResult'][0][0]['tgt']))
