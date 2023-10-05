answer = 0

def dfs(idx, numbers, target, value):
    global answer # 전역변수 사용한다는 선언

    length = len(numbers)
    # 전부 다 계산했을 때 target 과 같은 경우, 정답
    if(idx == length and target == value):
        answer += 1
        return
    # 전부 다 계산했을 때 target 과 다른 경우,
    if(idx == length):
        return 

    # 현재 값을 더하거나 빼서 value 로 설정, 다음 index 계산을 위해 dfs 반복
    dfs(idx+1, numbers, target, value+numbers[idx])
    dfs(idx+1, numbers, target, value-numbers[idx])


def solution(numbers, target):
    global answer # 전역변수 사용한다는 선언
    dfs(0, numbers, target, 0)
    return answer