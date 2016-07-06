#!/usr/bin/env python
# -*- coding: utf-8 -*-

ip = raw_input("Please input the numeric string: ")

count = 0
n = len(ip)
print u"ip划分情况如下："

if n >= 4 and n <= 12 :
    for i in range(n-3):
        if i > 2:
            break
        s1 = ip[0:i+1]
        if int(s1) > 255 or (len(s1) > 1 and s1[0] == '0'):
            break
        for j in range(i+1, n-2):
            if j-i > 3:
                break
            s2 = ip[i+1:j+1]
            if int(s2) > 255 or (len(s2) > 1 and s2[0] == '0'):
                break
            for k in range(j+1, n-1):
                if k-j > 3:
                    break
                s3 = ip[j+1:k+1]
                if int(s3) > 255 or (len(s3) > 1 and s3[0] == '0'):
                    break
                if n-k-1 > 3:
                    continue
                s4 = ip[k+1:]
                if int(s4) > 255 or (len(s4) > 1 and s4[0] == '0'):
                    continue
                print s1+'.'+s2+'.'+s3+'.'+s4
                count = count + 1

print u"划分ip总个数：",count
