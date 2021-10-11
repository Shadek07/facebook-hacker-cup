
import sys
import heapq
from enum import Enum
fp = open('traffic_control_input.txt', 'r')
tnum = int(fp.readline())
case = 1
f = open("B_out.txt", "w")

while tnum > 0:
    inp = fp.readline().split()
    inp = [int(t) for t in inp]
    n, m, a, b = inp[0], inp[1], inp[2], inp[3] 
    #print n
    f.write("Case #"+str(case)+": ")
    min_wait = n+m-1
    if min(a,b) < min_wait:
        f.write("Impossible\n")
        tnum -= 1
        case += 1
        continue
    town = [[1 for j in range(m)] for i in range(n)]
    for i in range(0, n-1):
        for j in range(1, m-1):
            town[i][j] = 2
    town[0][0] = a - (n+m-2)
    town[0][m-1] = b - (n+m-2)
    f.write("Possible\n")
    for i in range(n):
        for j in range(m):
            if j:
                f.write(" ")
            f.write(str(town[i][j]))
        f.write("\n")
    tnum -= 1
    case += 1
f.close()



