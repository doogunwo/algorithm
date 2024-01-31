from collections import deque

n = int(input())

for i in range(n):
    dq = deque()
    m = input()
    is_balanced = True  # 괄호의 균형을 확인하는 플래그

    for j in m:
        if j == "(":
            dq.append(j)
        else:
            if len(dq) == 0:
                is_balanced = False
                break
            else:
                dq.pop()

    if is_balanced and len(dq) == 0:
        print("YES")
    else:
        print("NO")
