import urllib.request
import os

def url_open(url):
    req = urllib.request.Request(url)
    req.add_header('User-Agent','Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.139 Safari/537.36')
    response = urllib.request.urlopen(url)
    html= response.read()
    print(html.decode('utf-8'))
    return html


def get_page(url):
    #读出该网页内所有内容
    html = url_open(url).decode('utf-8')
    print(html)
  
    #查找需要内容
    a= html.find('current-comment-page')+23
    b= html.find(']',a)
    print(html[a:b])
    return html[a:b]


def find_imgs(url):
    html = url_open(url).decode('utf-8')
    img_addrs = []

    a = html.find('img src=')
    
    while a != -1:
        b = html.find('.jpg',a,a+255)

        #找不到 find（）会返回-1
        if b != -1:
            img_addrs.append(html[a+9:b+4])

        else:
            b = a + 9

        a= html.find('img src=',b)
    for each in img_addrs:
        print(each)
        
   # return img_addrs

def save_imgs(folder,img_addrs):
    for each in img_addrs:
        filename = each.split('/')[-1]
        with open(filename,'wb') as f:
            img =url_open(each)
            f.write(img)

def download(folder = 'picture',page = 20):
    os.mkdir(folder)#建立文件夹
    os.chdir(folder)#改变目录进入到该文件夹

    url = "http://jandan.net/ooxx/"
    page_num = int(get_page(url))

    for i in range(page):
        page_num -= i
        page_url = url + 'page-' +str(page_num) + '#comments'
        img_addrs = find_imgs(page_url)
        save_imgs(folder,img_addrs)


if __name__ == '__main__':
    download()
