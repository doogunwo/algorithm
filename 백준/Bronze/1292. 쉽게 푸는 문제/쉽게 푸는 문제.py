n, m = map(int, input().split())
cnt = 1000
i = 1
result_list = []

while cnt > 0:
    for _ in range(i):
        if cnt > 0:
            result_list.append(i)
            cnt -= 1
        else:
            break
    i += 1

sequence_sum = sum(result_list[n-1:m])
print(sequence_sum)