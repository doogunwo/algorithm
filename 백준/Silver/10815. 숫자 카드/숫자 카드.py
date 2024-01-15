import sys
from collections import Counter

input = sys.stdin.readline

n = int(input())

n_list = list(map(int,input().split()))

m = int(input())

m_list = list(map(int,input().split()))

card_count = Counter(n_list)
result = [card_count[target] for target in m_list]
print(" ".join(map(str, result)))
