def solution(ing):
    answer = 0
    sum = []

    for i in ing:
        sum.append(i)
        if sum[-4:] == [1,2,3,1]:
            answer = answer +1
            for _ in range(4):
                sum.pop()
    

    return answer