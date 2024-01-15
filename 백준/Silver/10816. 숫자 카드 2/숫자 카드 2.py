from collections import Counter

# 입력 받기
n = int(input())
cards = list(map(int, input().split()))
m = int(input())
targets = list(map(int, input().split()))

# 카드의 개수 세기
card_count = Counter(cards)

# 결과 출력
result = [card_count[target] for target in targets]
print(" ".join(map(str, result)))
