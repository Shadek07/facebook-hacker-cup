import sys
fp = open('consistency_chapter_2_input.txt', 'r')
tnum = int(fp.readline())
case = 1
f = open("A2out.txt", "w")

while tnum > 0:
    S = str(fp.readline())
    S = S.rstrip()
    n = len(S)
    #print n
    dist = [ [float('inf') for j in range(26)] for i in range(26)]
    min_ans = float('inf')
    f.write("Case #"+str(case)+": ")
    m = int(fp.readline())
    for i in range(m):
        edge = str(fp.readline())
        edge = edge[0:2]
        #print edge
        a = ord(edge[0]) - ord('A')
        b = ord(edge[1]) - ord('A')
        dist[a][b] = 1

    for k in range(26):
        for i in range(26):
            for j in range(26):
                if i!=j and i!=k and j!=k:
                    if dist[i][k] < float('inf') and dist[k][j] < float('inf'):
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    #print dist
    for i in range(26):
        ans = 0
        for j in range(0, n):
            k = ord(S[j])-ord('A')            
            if k == i:
                continue
            if dist[k][i] == float('inf'):
                ans = -1
                break
            ans += dist[k][i]
        if ans != -1:            
            min_ans = min(min_ans, ans)
    if min_ans == float('inf'):
        f.write("-1\n")            
    else:
        f.write(str(min_ans)+"\n")
    tnum -= 1
    case += 1
f.close()

