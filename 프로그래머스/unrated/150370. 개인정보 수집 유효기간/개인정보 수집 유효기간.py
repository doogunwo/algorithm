import datetime
from dateutil.relativedelta import relativedelta
def solution(today, terms, privacies):
    answer = []

    today = datetime.datetime.strptime(today,'%Y.%m.%d')

    dic = {}
    for data in terms:
        code, month = data.split(" ")
        dic[code] = int(month)

    for i in range(len(privacies)):
        day, code = privacies[i].split(" ")
        day = datetime.datetime.strptime(day, '%Y.%m.%d')
        day = day + relativedelta(months=dic[code])

        if day <= today:
            answer.append(i + 1)

    return answer