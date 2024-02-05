n = int(input())

for i in range(n-1,-1,-1):

    space = i # 공백의 개수
    star = n-i #별의 개수
    
    text = " "*space + "*"*star
    print(text)
    