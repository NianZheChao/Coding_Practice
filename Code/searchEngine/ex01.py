import time


# BF算法
def BF(str1, str2):
    start = 0
    i = 0
    j = 0
    m = len(str1)
    n = len(str2)
    while i < m:
        while j < n:
            if(str1[i] == str2[j]):
                i += 1
                j += 1
            else:
                start += 1
                i = start
                j = 0
                break
            print('matched at ', i-len(str2))


BF('abcdjkefghijklmn', 'cd')


def p_next(str2):
    i = 0
    j = 1
    next = [0]*len(str2)
    next[0] = -1
    while(j < len(str2)):
        if(i == 0 and str2[i] != str2[j]):
            next[j] = 0
            j += 1
        elif(i != 0 and str2[i] != str2[j]):
            i = next[i-1]
        elif(str2[i] == str2[j]):
            next[j] = i+1
            i += 1
            j += 1
    return next


def kmp(str1, str2):
    i = 0
    j = 0
    next = p_next(str2)
    while(i < len(str1)):
        if(str1[i] == str2[j]):
            i += 1
            j += 1
            if(j >= len(str2)):
                print("匹配到的字串的下标在:", i-len(str2))
                break
        elif (str1[i] != str2[j]):
            if(j == 0):
                i += 1
            else:
                j = next[j]

    if(i == len(str1)):
        print("no substr")
