import os
import tkinter as tk
from tkinter import filedialog


def getShingle(s, k):
    dic = dict()
    for i in range(0, len(s) - k + 1):
        s1 = s[i:i + k]  # 拆分词
        j = dic.get(s1)
        if j:
            dic[s1] += 1
        else:
            dic[s1] = 1
    # print(dic)
    return dic


def getSimilarity(s1, s2, k):
    if s1 == s2:
        return 1
    set1 = set()
    set2 = set()
    profile1 = getShingle(s1, k)
    profile2 = getShingle(s2, k)

    for i in profile1.keys():
        set1.add(i)  # 加入到set中
    for i in profile2.keys():
        set2.add(i)  # 加入到set中
    # print(set1)
    # print(set2)
    return 1.0 * len(set1 & set2) / len(set1 | set2)
    # inter = len(profile1.keys()) + len(profile2.keys()) - len(set1)
    # return 1.0 * inter / len(set1)


def readFile():
    root = tk.Tk()
    root.withdraw()
    filePath = filedialog.askopenfilename()
    with open(filePath, 'r', encoding='UTF-8') as f:
        string = f.read()
    return string


def compare_two_file():
    s1 = readFile()
    s2 = readFile()
    a = getSimilarity(s1, s2, 3)
    return a


def getSimilarityInFolder():
    root = tk.Tk()
    root.withdraw()
    folderPath = filedialog.askdirectory()
    FolderFile = os.listdir(folderPath)

    s1 = readFile()
    for i in range(0, len(FolderFile)):
        if 'txt' in str(FolderFile[i]):
            file = open(str(folderPath +'\\'+ str(FolderFile[i])), 'r', encoding='UTF-8')
            s2 = file.read()
            print('与 ' + FolderFile[i] + ' 文件相比： ', end='')
            Sim = getSimilarity(s1, s2, 2)
            print(Sim)
