# 숫자의 개수 N 입력받기
n = int(input())

# 숫자가 연속적으로 주어진 문자열 입력받기
numbers = input()

sum3 = 0
# 각 숫자의 합 계산
for num in numbers:
    sum3 = sum3 + int(num)
# 결과 출력
print(sum3)
