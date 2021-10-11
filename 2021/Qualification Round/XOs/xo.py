import sys
fp = open('xs_and_os_input.txt', 'r')
tnum = int(fp.readline())
case = 1
f = open("xoout.txt", "w")

def is_valid(line):
    return 'O' not in line

while tnum > 0:
    n = int(fp.readline())
    min_x = float('inf')
    f.write("Case #"+str(case)+": ")
    B = [ [None for j in range(n)] for i in range(n)]
    
    for i in range(n):
        line = str(fp.readline())
        for j in range(n):
            B[i][j] = line[j]
    valid_lines = []
    #row process
    for i in range(n):
        line = ''.join(B[i][j] for j in range(n))                
        if is_valid(line):
            min_x = min(min_x, n-line.count('X'))
            valid_lines.append(line)
    #col process
    for j in range(n):
        line = ''.join(B[i][j] for i in range(n))
        if is_valid(line):
            min_x = min(min_x, n-line.count('X'))
            valid_lines.append(line)
    tnum -= 1
    case += 1
    if min_x == float('inf'):
        f.write('Impossible\n')
        continue
    if min_x == 1:
        both = set()
        for i in range(n):
            for j in range(n):
                if B[i][j] == '.':
                    row_line = ''.join(B[i][k] for k in range(n))        
                    col_line = ''.join(B[k][j] for k in range(n))        
                    if is_valid(row_line) and is_valid(col_line) and row_line.count('.') == 1 and col_line.count('.')== 1:
                        both.add((i,j))
        cnt = 0
        for line in valid_lines:
            if n-line.count('X') == min_x:
                cnt+=1
        cnt -= len(both)
        f.write(str(min_x) + ' '+str(cnt)+'\n')
    else:
        cnt = 0
        for line in valid_lines:
            if n-line.count('X') == min_x:
                cnt+=1
        f.write(str(min_x) + ' '+ str(cnt)+'\n')
            
f.close()


