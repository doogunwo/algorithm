n, m = map(int, input().split())
r, c, d = map(int, input().split())

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

arr = [list(map(int, input().split())) for _ in range(n)]

# 방문 여부를 체크하는 배열 대신, 방문한 곳을 2로 표시
arr[r][c] = 2
cnt = 1

while True:
    flag = 0
    for _ in range(4):
        d = (d + 3) % 4
        nr = r + dr[d]
        nc = c + dc[d]

        if 0 <= nr < n and 0 <= nc < m and arr[nr][nc] == 0:
            if arr[nr][nc] == 0:
                cnt += 1
                r, c = nr, nc
                arr[r][c] = 2  # 방문한 곳을 2로 표시
                flag = 1
                break
    
    if flag == 0:
        if arr[r - dr[d]][c - dc[d]] == 1:
            print(cnt)
            break
        else:
            r, c = r - dr[d], c - dc[d]
