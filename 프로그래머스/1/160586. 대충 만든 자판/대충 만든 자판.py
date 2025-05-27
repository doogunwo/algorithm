def solution(keymap, targets):
    answer = []
    
    press = {}#키맵에서 각 문자 최소 누르기 횟수 저장
    for key in keymap:
        for idx, char in enumerate(key):
            if char in press:
                press[char] = min(press[char], idx+1)
            else:
                press[char] = idx + 1    
    
    
    for target in targets:
        total_presses = 0
        for char in target:
            if char in press:
                total_presses = total_presses + press[char]
            else:
                total_presses = -1
                break
        answer.append(total_presses)
    
    return answer