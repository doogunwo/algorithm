# 숫자의 개수 N 입력받기
n = int(input())

# 숫자가 연속적으로 주어진 문자열 입력받기
numbers = input()

# 각 숫자의 합 계산
sum_of_numbers = sum(int(num) for num in numbers)

# 결과 출력
print(sum_of_numbers)
