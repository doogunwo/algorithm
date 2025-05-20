


def solution(n, w, num):
    # 박스 정리
    MAX_ROW = n//w+1
    boxes = []
    for row in range(MAX_ROW):
        boxes.append([row*w + i if row*w + i <= n else 0 for i in range(1, w+1)][::-1 if row%2==1 else 1])
    
    # 박스 탐색
    for r in range(MAX_ROW):
        for c in range(w):
            if boxes[r][c] != num:
                continue
            
            # 박스 발견
            res = 0
            for i in range(MAX_ROW):
                res += 1
                r+=1
                if r >= MAX_ROW:
                    return res
                if boxes[r][c] == 0:
                    return res

print(solution(22,6,8))