def hanoi(n, start, end, sub):
    print('hanoi')
    if n==1:
        return [[start,end]]
    else:
        path = []
        path = path + hanoi(n-1, start, sub, end)
        path = path + [[start,end]]
        path = path + hanoi(n-1, sub, end, start)

        return path

def solution(n):
    answer = hanoi(n,1,3,2)
    return answer


