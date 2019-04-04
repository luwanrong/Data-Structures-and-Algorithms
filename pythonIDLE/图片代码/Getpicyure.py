import urllib.request
import re
def url_open(url):
    req = urllib.request.Request(url)
    req.add_header('User-Agent','Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.139 Safari/537.36')
    response = urllib.request.urlopen(url)
    html= response.read()
    
    return html


def get_img(html):
    #正则表达式
    p = r'<img class="BDE_Image" src="([^"]+\.jpg)"'
    imglist = re.findall(p,html)


    
    for each in imglist:
        filename = each.split('/')[-1]
        with open(filename,'wb') as f:
            img =url_open(each)
            f.write(img)



if __name__ == '__main__':
    url = 'https://tieba.baidu.com/p/3823765471'
    get_img(url_open(url).decode("utf-8"))
