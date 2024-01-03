import sys
from collections import deque

input = sys.stdin.readline

def solution(n, m, arr):
    q = deque([(i, importance) for i, importance in enumerate(arr)])
    cnt = 0

    while q:
        cur_doc = q.popleft()
        if any(cur_doc[1] < doc[1] for doc in q):
            q.append(cur_doc)
        else:
            cnt += 1
            if cur_doc[0] == m:
                print(cnt)
                return

w = int(input())

for _ in range(w):
    n, m = map(int, input().split())
    arr = list(map(int, input().split()))
    solution(n, m, arr)
