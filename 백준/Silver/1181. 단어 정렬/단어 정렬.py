n = int(input())  # 단어의 개수 입력
words = [input() for _ in range(n)]  # 단어 입력

# 중복 제거
words = list(set(words))

# 람다 함수를 사용하여 먼저 길이로, 그 다음 사전 순으로 정렬
words.sort(key=lambda x: (len(x), x))

# 정렬된 단어 출력
for word in words:
    print(word)
