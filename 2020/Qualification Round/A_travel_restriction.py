
import sys
fp = open('travel_restrictions_input.txt', 'r')
t = int(fp.readline())
case = 1
f = open("travel_restriction.txt", "w")

while t>0:
    n = int(fp.readline())
    I = fp.readline()
    O = fp.readline()
    A = [ ['N' for j in range(n)] for i in range(n)]
    for i in range(n):
        a = i-1 if i-1 >= 0 else i
        b = i+1 if i+1 < n else i
        for j in range(a, b+1):
            if i == j:
                A[i][j] = 'Y'
            else:
                if I[j] == 'Y' and O[i] == 'Y':
                    A[i][j] = 'Y'
    #print A
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if k != i and k!= j and i!=j:
                    if A[i][k] == 'Y' and A[k][j] == 'Y':
                        A[i][j] = 'Y'
    f.write("Case #"+str(case)+":\n")
    case+=1
    for i in range(n):
        f.write(''.join(A[i])+'\n')
    t -= 1
f.close()
