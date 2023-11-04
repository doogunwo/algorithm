import sys

n, m = map(int, input().split())

# 각 강의실의 끝 시각을 기록하는 리스트
end_times = [0] * n

results = []  # 예약 가능 여부를 저장할 리스트

for _ in range(m):
    room_number, start_time, end_time = map(int, sys.stdin.readline().split())
    room_number -= 1  # 강의실 번호를 0부터 시작하도록 조정
    
    # 이용 시작 시각이 현재 강의실 끝 시각보다 늦거나 같다면 예약 가능
    if start_time >= end_times[room_number]:
        end_times[room_number] = end_time
        results.append("YES")
    else:
        results.append("NO")

# 결과 출력
for result in results:
    print(result)
