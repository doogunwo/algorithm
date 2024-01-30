n = int(input())
points = list(map(int, input().split()))

# 람다 함수를 사용하여 새로운 점수 계산
new_scores = list(map(lambda x: x / max(points) * 100, points))

# 새로운 평균 계산
avg = sum(new_scores) / n

print(avg)
