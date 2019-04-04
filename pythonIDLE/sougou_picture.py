import urllib.request
import os

def downloadmm(folder='picture1'):
        os.mkdir(folder)#建立文件夹
        os.chdir(folder)#改变目录进入到该文件夹
        url = "http://pic.sogou.com/pics/recommend?category=%E7%BE%8E%E5%A5%B3&imageid=12659838#%E9%9D%92%E6%98%A5"
        req = urllib.request.Request(url)
        req.add_header('User-Agent','Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.139 Safari/537.36')
        response = urllib.request.urlopen(url)
        html= response.read()

        a = html.find('img src=')
        

if __name__ == '__main__':
        downloadmm()

