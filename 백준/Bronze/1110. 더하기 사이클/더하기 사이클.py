N = int(input())
cnt=0
n4 =N

#26일때
while(1):
        cnt=cnt+1
        n1, n2 = divmod(N, 10)# n1=2 n2 =6
        if n1+n2 >9: #10이상일때 10으로 나눠서 나머지를 더함
            n3 = (n1+n2) %10
            N = n2*10 + n3
        else:
            N= n2*10+(n1+n2)

        if(N==n4):
            break




print(cnt)

