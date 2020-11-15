import requests
from bs4 import BeautifulSoup
import re
import urllib
import os


def crawl_content(url):
    """提取网页内容"""
    resq = requests.get(url)
    resq.encoding = 'utf-8'
    content = resq.text
    return content


def extract_title(content):
    soup = BeautifulSoup(content, 'html.parser')
    t = soup.find('title')
    return t


def remove_empty_line(content):
    r = re.compile(r'''^\s+$''', re.M | re.S)
    s = r.sub('', content)
    r = re.compile(r'''\n+''', re.M | re.S)
    s = r.sub('\n', s)
    return s


def remove_js_css(content):
    r = re.compile(r'''<script.*?</script>''', re.I | re.M | re.S)
    s = r.sub('', content)
    r = re.compile(r'''<style.*?</style>''', re.I | re.M | re.S)
    s = r.sub('', s)
    r = re.compile(r'''<!--.*?-->''', re.I | re.M | re.S)
    s = r.sub('', s)
    r = re.compile(r'''<meta.*?>''', re.I | re.M | re.S)
    s = r.sub('', s)
    r = re.compile(r'''<ins.*?</ins>''', re.I | re.M | re.S)
    s = r.sub('', s)
    return s


def remove_any_tag(s):
    s = re.sub(r'''<[^>]+>''', '', s)
    return s.strip()


def extract_text(content):
    s = remove_empty_line(remove_js_css(content))
    s = remove_any_tag(s)
    s = remove_empty_line(s)
    return s


def extract_a_label(content):
    soup = BeautifulSoup(content, 'html.parser')
    alink = soup.find_all('a')
    return alink


def getHtml(url):
    page = urllib.request.urlopen(url)
    html = page.read()
    return html.decode('UTF-8')


def getImg(html):
    reg = r'src="(.+?\.jpg)" pic_ext'
    imgre = re.compile(reg)
    imglist = imgre.findall(html)
    x = 0
    path = 'D:\\2020\\学习\\2020秋\\搜索引擎\\实验三\\img'
    paths = path+'\\'
    for imgurl in imglist:
        urllib.request.urlretrieve(imgurl, '{}{}.jpg'.format(paths, x))
        x = x + 1
    return imglist


def crawl_auto(content):
    path = 'D:\\2020\\学习\\2020秋\\搜索引擎\\实验三\\'
    if not os.path.isdir(path):
        os.makedirs(path)
    content = crawl_content(content)
    title = extract_title(content).text
    f_title = open('D:\\2020\\学习\\2020秋\\搜索引擎\\实验三\\title.txt', 'w', encoding='UTF-8')
    f_title.write(title)

    f_a = open('D:\\2020\\学习\\2020秋\\搜索引擎\\实验三\\a.txt', 'w', encoding='UTF-8')
    alink = extract_a_label(content)
    for link in alink:
        a = link.get('href')
        key = link.string
        if key is not None and a is not None:
            f_a.write(key)
            f_a.write(a)
            f_a.write('\n')
        print('Crawled one href successfully!')


# content = crawl_content('https://www.cnblogs.com/')
#
# title = extract_title(content).text
# f_title = open('D:\\2020\\学习\\2020秋\\搜索引擎\\实验三\\title.txt', 'w')
# f_title.write(title)
#
# f_a = open('D:\\2020\\学习\\2020秋\\搜索引擎\\实验三\\source_a.txt', 'w', encoding='UTF-8')
# alink = extract_a_label(content)
# for link in alink:
#     a = link.get('href')
#     key = link.string
#     if key is not None and a is not None:
#         f_a.write(a)
#         f_a.write('\n')

# getImg(getHtml('http://tieba.baidu.com/p/2460150866'))


with open('D:\\2020\\学习\\2020秋\\搜索引擎\\实验三\\source_a.txt', 'r') as f:
    hrefList = [line.rstrip('\n') for line in f]
    print(hrefList)
for href in hrefList:
    if href.startswith('http'):
        href = href
    else:
        href = 'https://www.cnblogs.com/' + href
    crawl_auto(href)
# for href in hrefList:
#     print(href)

