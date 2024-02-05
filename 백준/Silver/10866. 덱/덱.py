from collections import deque
import sys

n = int(sys.stdin.readline().strip())  # 명령의 수 입력 받기
dq = deque()  # 덱 생성

for _ in range(n):
    command = sys.stdin.readline().strip().split()
    cmd = command[0]

    if cmd == "push_front":
        dq.appendleft(command[1])
    elif cmd == "push_back":
        dq.append(command[1])
    elif cmd == "pop_front":
        print(dq.popleft() if dq else -1)
    elif cmd == "pop_back":
        print(dq.pop() if dq else -1)
    elif cmd == "size":
        print(len(dq))
    elif cmd == "empty":
        print(0 if dq else 1)
    elif cmd == "front":
        print(dq[0] if dq else -1)
    elif cmd == "back":
        print(dq[-1] if dq else -1)
