N = int(input())

for i in range(N):
    a, b = map(int, input().split())
    a %= 10
    
    if a == 0:
        print(10)
    elif a == 1 or a == 5 or a == 6:
        print(a)
    elif a == 4 or a == 9:
        b = b % 2
        if b == 1:
            print(a)
        else:
            print((a * a) % 10)
    else:
        b = b % 4
        if b == 0: # b가 4인 경우 b % 4 = 1로 되어 계산하는 것 방지
            print((a**4) % 10 % 10 % 10)
        else:
            print((a**b) % 10 % 10 % 10)