
import sys
import heapq
from enum import Enum
fp = open('consistency_chapter_1_input.txt', 'r')
tnum = int(fp.readline())
case = 1
f = open("consistency.txt", "w")

class LetterType(Enum):
    vowel = 0
    consonant = 1

vowels = ['A', 'E', 'I', 'O', 'U']
consonants = ['B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M','N','P','Q','R','S','T','V','W','X','Y','Z']

def getLetterType(letter):
    if letter in vowels:
        return LetterType.vowel
    return LetterType.consonant

while tnum > 0:
    S = str(fp.readline())
    S = S.rstrip()
    n = len(S)
    #print n
    min_ans = float('inf')
    f.write("Case #"+str(case)+": ")
    for i in range(26):
        candidate = chr(i+ord('A'))
        #print candidate
        candidate_type = getLetterType(candidate)
        #print candidate_type
        ans = 0
        for j in range(0, n):
            ltype = getLetterType(S[j])
            #print ltype, S[j]
            if S[j] == candidate:
                #print ans
                continue
            if candidate_type == ltype:
                ans += 2
            else:
                ans += 1
            #print ans
            
        min_ans = min(min_ans, ans)
            
    f.write(str(min_ans)+"\n")
    tnum -= 1
    case += 1
f.close()
