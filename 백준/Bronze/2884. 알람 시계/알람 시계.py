# 입력 받기
H, M = map(int, input().split())

# 45분 일찍 알람 설정하기
if M >= 45:
    M -= 45
else:
    M += 15
    H -= 1
    if H < 0:
        H = 23

# 결과 출력
print(H, M)