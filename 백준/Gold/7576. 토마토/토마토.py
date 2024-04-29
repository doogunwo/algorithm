from collections import deque
import sys
input = sys.stdin.read

def bfs():
    days = -1
    while queue:
        days += 1
        for _ in range(len(queue)):
            x, y = queue.popleft()
            for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] == 0:
                    grid[nx][ny] = 1
                    queue.append((nx, ny))
    for row in grid:
        if 0 in row:
            return -1
    return days

# 입력 처리
data = input().split()
m, n = int(data[0]), int(data[1])
grid = []
index = 2
for i in range(n):
    grid.append(list(map(int, data[index:index+m])))
    index += m

# BFS 초기화
queue = deque()
for i in range(n):
    for j in range(m):
        if grid[i][j] == 1:
            queue.append((i, j))

# 결과 출력
print(bfs())
