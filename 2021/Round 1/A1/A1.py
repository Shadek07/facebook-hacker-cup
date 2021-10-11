
import sys
import heapq
from enum import Enum
fp = open('weak_typing_chapter_1_input.txt', 'r')
tnum = int(fp.readline())
case = 1
f = open("A1.txt", "w")

while tnum > 0:
    n = int(fp.readline())
    S = fp.readline().rstrip()
    #print n
    f.write("Case #"+str(case)+": ")
    segments = 0
    curr = 'A'
    for i in range(0, n):
        if S[i] == 'F':
            continue
        if curr != S[i]:
            segments += 1
            curr = S[i]
                    
    f.write(str(max(0, segments-1))+"\n")
    tnum -= 1
    case += 1
f.close()

