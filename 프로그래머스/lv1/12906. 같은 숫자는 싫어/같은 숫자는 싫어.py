def solution(arr):
    answer = []
    start = arr[0]
    answer.append(start)
    for i in arr:
        if start == i:
            pass
        if start != i:
            start = i 
            answer.append(start)
    return answer