def solution(a, b, n):
    answer = 0
    # 기본 로직
    
    while(n>=a):
        remain_bottle = n%a
        n = (n//a) * b
        answer = answer +n
        n = n + remain_bottle
    return answer