while True:
    n = input()
    if n == "0":  # 입력된 값이 문자열 "0"인 경우 종료
        break
    
    if n == n[::-1]:  # 입력된 값과 그 값을 뒤집은 값이 같은지 비교
        print('yes')
    else:
        print('no')
