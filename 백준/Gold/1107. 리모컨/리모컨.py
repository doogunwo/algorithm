# 5457
# 3
# 6 7 8

def can_press(ch,broken_buttons):
    if ch == 0:
        return False if '0' in broken_buttons else True
    
    while ch:
        if str(ch % 10) in broken_buttons:
            return False
        ch = ch//10

    return True


def solution(target_channel,broken_buttons):
    min_click = abs(100-target_channel)
    for ch in range(1000001):
        if can_press(ch, broken_buttons):
            clicks = len(str(ch)) + abs(ch - target_channel)
            min_click = min(min_click, clicks)
    
    return  min_click
        

target_channel = int(input())  # 목표 채널
n = int(input())  # 고장난 버튼의 수
broken_buttons = set(input().split()) if n > 0 else set()

result = solution(target_channel,broken_buttons)
print(result)