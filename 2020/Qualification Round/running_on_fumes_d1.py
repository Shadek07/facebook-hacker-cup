import sys
import heapq
fp = open('running_on_fumes_chapter_1_input.txt', 'r')
tnum = int(fp.readline())
case = 1
f = open("running_on_fumes_d1.txt", "w")

while tnum > 0:
    line = fp.readline().split()
    n, m = int(line[0]), int(line[1])
    C = [-1]*n
    for i in range(n):
        C[i] = int(fp.readline())
    pq = []
    ans = -1
    heapq.heappush(pq, (0, n-1))
    i = n-2
    while i >= 0:
        t = None
        while pq:
            t = heapq.heappop(pq)
            if i+m >= t[1] and t[0] < float('inf'):
                heapq.heappush(pq, t)
                break
        #print i, t
        if t is None:
            if i+m < n-1:
                break
            else:
                heapq.heappush(pq, (C[i], i))
        else:
            if C[i] > 0:
                heapq.heappush(pq, ( (C[i] if i>0 else 0)+t[0], i))
            else:
                heapq.heappush(pq, (float('inf'), i))
        if i == 0:
            ans = heapq.heappop(pq)[0]
            break
        i -= 1
    if ans == float('inf'):
        ans = -1
    f.write("Case #"+str(case)+": ")
    case += 1
    tnum -= 1
    f.write(str(ans)+"\n")

f.close()


if n == 0:
    return []
if n==1:
    return []
prefMulLeft = [1]*n
prefMulRight = [1]*n

for i in range(n):
    if i == 0:
      prefMulLeft[0] = arr[0]
      continue
    prefMulLeft[i] = prefMulLeft[i-1]*arr[i]

for i in range(n-1,-1,-1):
    if i == n-1:
      prefMulRight[i] = arr[i]
      continue
    prefMulRight[i] = prefMulRight[i+1]*arr[i]

ans = [0]*n

for i in range(n):
    if i == 0:
      ans[i] = prefMulRight[i+1]
      continue
    if i==n-1:
      ans[i] = prefMulLeft[i-1]
      continue
    ans[i] = prefMulLeft[i-1]*prefMulRight[i+1]

return ans


