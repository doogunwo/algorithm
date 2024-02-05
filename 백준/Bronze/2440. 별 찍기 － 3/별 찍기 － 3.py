n = int(input())

for i in range(n, 0, -1):  # n부터 1까지 역순으로 반복
    text = '*' * i  # i개의 별을 문자열로 생성
    print(text)  # 생성된 문자열 출력
