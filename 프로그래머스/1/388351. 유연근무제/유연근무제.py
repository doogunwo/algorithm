def solution(schedules, timelogs, startday):
    def to_minutes(t):
        return (t // 100) * 60 + t % 100

    answer = 0
    for i, logs in enumerate(timelogs):
        deadline = to_minutes(schedules[i]) + 10
        day = startday
        is_late = False

        for log in logs:
            if day not in (6, 7):  # 평일만 체크
                if to_minutes(log) > deadline:
                    is_late = True
                    break
            day = day + 1 if day < 7 else 1

        if not is_late:
            answer += 1

    return answer
