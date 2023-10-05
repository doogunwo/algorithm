def solution(n):
    answer = 0
    x = 1
    while(1):
        if n%x != 1:
            x = x+1
        else:
            break
    answer=x
   
    return answer