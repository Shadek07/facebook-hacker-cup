
import sys
fp = open('alchemy_input.txt', 'r')
t = int(fp.readline())
case = 1
f = open("alchemy.txt", "w")

while t>0:
    n = int(fp.readline())
    S = fp.readline()
    invalid = ["AAA", "BBB"]
    f.write("Case #"+str(case)+":")
    case += 1
    t -= 1
    types = []
    cnts = []
    cnt = 1
    for i in range(1, n):
        if S[i] != S[i-1]:
            cnts.append(cnt)
            types.append(S[i-1])
            cnt = 1
        else:
            cnt += 1
    cnts.append(cnt)
    ans = True
    while True:
        if len(cnts) == 1:
            if cnts[0] != 1:
                ans = False
            break
        if len(cnts) == 2:
            if abs(cnts[0]-cnts[1]) > 1:
                ans = False
            break
        if cnts[0] > cnts[1]:
            a = cnts[0] - cnts[1] + cnts[2]
            cnts.pop(0)
            cnts.pop(0)
            cnts.pop(0)
            cnts.insert(0, a)
        elif cnts[1] > cnts[0]:
            a = cnts[1] - cnts[0]
            cnts.pop(0)
            cnts.pop(0)
            cnts.insert(0, a)
        else:
            cnts.pop(0)
            cnts.pop(0)
    if ans:
        f.write(" Y\n")
    else:
        f.write(" N\n")

f.close()

