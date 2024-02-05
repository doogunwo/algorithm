import sys
chess=[['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
       ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
       ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
       ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
       ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
       ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
       ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
       ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W']]
n, m = map(int, sys.stdin.readline().split())
res=n*m
inp = []
for _ in range(n):
    inp.append(list(sys.stdin.readline().strip('\n')))
def ch(x, y):
    cnt=0
    for i in range(8):
        for j in range(8):
            if chess[i][j]==inp[x+i][y+j]:
                cnt+=1
    return min(cnt, 64-cnt)
for i in range(n-7):
    for j in range(m-7):
        res=min(res, ch(i, j))
print(res)#문제 개어렵