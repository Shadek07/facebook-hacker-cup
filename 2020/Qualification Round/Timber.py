
import sys
import heapq
fp = open('timber_input.txt', 'r')
tnum = int(fp.readline())
case = 1
f = open("Timber.txt", "w")

while tnum > 0:
    n = int(fp.readline())
    P = [(-1, -1)]*n
    for i in range(n):
        inp = fp.readline().split()
        P[i] = (int(inp[0]), int(inp[1]))
    P.sort(key=lambda x: x[0])

    f.write("Case #"+str(case)+": ")
    RightFallingMax = dict()
    LeftFallingMax = dict()
    RightFallingMax[P[0][0]+P[0][1]] = P[0][1]
    ans = max([p[1] for p in P])
    for i in range(1, n):
        if P[i][0] in RightFallingMax:
            prevMax = RightFallingMax[P[i][0]]
        else:
            prevMax = 0
        newX = P[i][0] + P[i][1]
        if newX not in RightFallingMax:
            RightFallingMax[newX] = prevMax + P[i][1]
        elif RightFallingMax[newX] < prevMax + P[i][1]:
            RightFallingMax[newX] = prevMax + P[i][1]
        ans = max(ans, RightFallingMax[newX])

    LeftFallingMax[P[n-1][0]-P[n-1][1]] = P[n-1][1]
    for i in range(n-2, -1, -1):
        if P[i][0] in LeftFallingMax:
            prevMax = LeftFallingMax[P[i][0]]
        else:
            prevMax = 0
        newX = P[i][0] - P[i][1]
        if newX not in LeftFallingMax:
            LeftFallingMax[newX] = prevMax + P[i][1]
        elif LeftFallingMax[newX] < prevMax + P[i][1]:
            LeftFallingMax[newX] = prevMax + P[i][1]
        ans = max(ans, LeftFallingMax[newX])
    for i in range(0, n-1):
        rfallpnt = P[i][0] + P[i][1]
        if rfallpnt in RightFallingMax and rfallpnt in LeftFallingMax:
            ans = max(ans, RightFallingMax[rfallpnt] + LeftFallingMax[rfallpnt])

    case += 1
    tnum -= 1
    f.write(str(ans)+"\n")
f.close()
