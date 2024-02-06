n = int(input())
start = 666
count = 0

while True:
    if '666' in str(start):
        count += 1

    if count == n:
        print(start)
        break

    start += 1
