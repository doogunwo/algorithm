n = int(input())
for i in range(n):

    R, S = input().split()
    output = ''.join(char * int(R) for char in S)
    print(output)
