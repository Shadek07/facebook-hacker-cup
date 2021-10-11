import sys
import math
import heapq
from collections import deque
fp = open('gold_mine_chapter_1_input.txt', 'r')
tnum = int(fp.readline())
case = 1
f = open("c1out.txt", "w")

while tnum > 0:
    n = int(fp.readline())
    C = fp.readline().split() 
    C = [int(ci) for ci in C]
    max_ans = float('-inf')
    adj = [[] for i in range(n)]
    f.write("Case #"+str(case)+": ")
    for i in range(n-1):
        ab = fp.readline().split()
        a, b = int(ab[0])-1, int(ab[1])-1
        adj[a].append(b)
        adj[b].append(a)
        
    pathsum = [ 0 for i in range(n)]
    pathsum[0] = C[0]
    L = [ 0 for i in range(n)]
    P = [0 for i in range(n)]
    T = [0 for i in range(n)]
    L[0] = 0
    P[0] = -1
    T[0] = 0
    q = deque([(0, -1, 0)])
    H = 0
    while q:
        node, parent, level = q[0]
        q.popleft()
        for x in adj[node]:
            if x == parent:
                continue
            L[x] = level + 1
            P[x] = node
            pathsum[x] = pathsum[node] + C[x]
            q.append((x, node, level+1)) 
            H = max(H, level+1) 

    if H == 0:
        f.write(str(C[0])+"\n")
        tnum -= 1
        case += 1
        continue
        
    nr = int(math.sqrt(H*1.0)) 
    #print nr

    def dfs(root, node, parent, nr):
        if L[node] < nr:
            T[node] = root
        elif L[node]%nr == 0:
            T[node] = P[node] 
        else:
            T[node] = T[P[node]]
        for x in adj[node]:
            if x == parent:
                continue
            dfs(root, x, node, nr)

    def LCA(x, y):
        while T[x] != T[y]:
            if L[x] > L[y]:
                x = T[x] 
            else: 
                y = T[y]
        while x!= y:
            if L[x] > L[y]:
                x = P[x]
            else:
                y = P[y]
        return x    

    dfs(0, 0,-1, nr)
    for x in adj[0]:
        max_ans = max(max_ans, pathsum[x])
    for i in range(1, n):
        for j in range(1, n):
            if i == j:
                continue
            if i in adj[j]:
                continue
            if LCA(i, j) == 0:
                max_ans = max(max_ans, pathsum[i] + pathsum[j] - C[0])
            
    for i in range(1, n):
        if i not in adj[0]:
            max_ans = max(max_ans, pathsum[i])    
    
    f.write(str(max_ans)+"\n")
    tnum -= 1
    case += 1
f.close()

