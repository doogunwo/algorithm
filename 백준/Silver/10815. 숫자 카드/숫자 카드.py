import sys

input = sys.stdin.readline

def count_elements(iterable):
    element_count = {}
    for element in iterable:
        if element in element_count:
            element_count[element] += 1
        else:
            element_count[element] = 1
    return element_count

n = int(input())
n_list = list(map(int, input().split()))
m = int(input())
m_list = list(map(int, input().split()))

# 직접 만든 count_elements 함수 사용
card_count = count_elements(n_list)

result = [card_count.get(target, 0) for target in m_list]
print(" ".join(map(str, result)))
