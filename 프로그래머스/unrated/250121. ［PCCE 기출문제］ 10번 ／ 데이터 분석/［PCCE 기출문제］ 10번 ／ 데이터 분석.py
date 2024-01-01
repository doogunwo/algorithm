def solution(data, ext, val_ext, sort_by):

# 데이터 타입
    data_type = {
        "code" : 0,
        "date" : 1,
        "maximum" : 2,
        "remain" : 3
        }

    filtered_data = [d for d in data if d[data_type[ext]] < int(val_ext)]
    # filtered_data를 sort_by를 기준으로 다시 오름차순 정렬
    sorted_filtered_data = sorted(filtered_data, key=lambda x: x[data_type[sort_by]])
    return sorted_filtered_data