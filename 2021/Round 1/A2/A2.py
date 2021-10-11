
import sys
import heapq
from enum import Enum
fp = open('weak_typing_chapter_2_input.txt', 'r')
tnum = int(fp.readline())
case = 1
f = open("A2_out.txt", "w")

while tnum > 0:
    n = int(fp.readline())
    S = fp.readline().rstrip()
    #print n
    f.write("Case #"+str(case)+": ")
    segments = 0
    cnt = 'X' in S
    cnt += 'O' in S
    if cnt < 2:
        f.write(str(0)+"\n")
        tnum -= 1
        case += 1
        continue
    isEndOfSegment = set() #is index i the end of a segment. A segment ends with X or O and possible some F's in the beginning or middle
    i = n-1
    while i>=0:
        if S[i] in ['X', 'O']:
            break
        i-=1
    curr = S[i]
    i-=1
    while i>=0:
        if S[i] == 'F':
            i -= 1
            continue
        if S[i] != curr:
            isEndOfSegment.add(i)
        curr = S[i]
        i -= 1
    
    ans = 0                            
    current_addition = 0
    segment_cnt = 0
    segment_sizes = []
    M = 1000000007
    i = 0
    segment_sum = 0
    last_segment_index = -1
    while i < n:
        if S[i] in ['X', 'O']:
            break
        i += 1
    while i < n:
        j = i
        new_segment = False
        size = 0
        while j < n:
            if S[j] in ['X', 'O'] and S[j] != S[i]:
                break
            ans = (ans + current_addition)%M
            if j in isEndOfSegment:
                new_segment = True
                size = j - last_segment_index
                last_segment_index =  j
            j += 1    
        if new_segment:
            current_addition = current_addition + segment_sum + size
            segment_sum += size
        i = j
                
    f.write(str(ans)+"\n")
    tnum -= 1
    case += 1
f.close()


