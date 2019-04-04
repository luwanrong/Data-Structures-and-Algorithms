from lxml import etree
import requests


url = 'https://www.cnblogs.com/'

headers = {'user-agent': 'Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/67.0.3396.99 Safari/537.36'}

page = 1
num = 1
while True:
    zhuye_url = requests.get(url,headers).text

    index = etree.HTML(zhuye_url)
    print(index)

    tz_url = index.xpath('//div[@class = "post_item_body"]/h3/a/@href') #返回列表
    #print(tz_url)
    next_url = index.xpath('//*[@id="paging_block"]/div/a[last()]/@href')#返回列表
    next_text = index.xpath('//*[@id="paging_block"]/div/a[last()]/text()')
    #print(next_url)

    for i in tz_url:
        re = requests.get(i,headers).text
        html = etree.HTML(re)
        #print(html)
        tz_title = html.xpath('//a[@id = "cb_post_title_url"]/text()')#返回列表  list
        #print(tz_title)
        tz_content = html.xpath('string(//div[@id="cnblogs_post_body"])')# 返回 str
        #print(tz_content)

        #保存文件
        with open('cn-blogs.csv','a+',encoding = 'utf-8') as file:
            file.write(tz_title[0] + '\n')#tz_title为列表
            file.write(tz_content + '\n')
            file.write('*'*200 + '\n')
            print('第{0}页第{1}篇帖子'.format(page,num))
            num+=1
    if next_text[0] == 'Next >':
    #if next_url[0].xpath('text()')[0] == 'Next >':
        #url = 'https://www.cnblogs.com'+ next_url[0].xpath('@href')[0]
        url = 'https://www.cnblogs.com'+ next_url[0]
        print(url)
        page+=1
        num = 1   
    else:
        break

