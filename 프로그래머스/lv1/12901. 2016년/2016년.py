from datetime import datetime

def solution(a, b):
    answer = ''
    dateDict = {0:"MON",1:"TUE",2:"WED",3:"THU",4:"FRI",5:"SAT",6:"SUN"}
    date ='2016-'+str(a)+"-"+str(b)
    datetime_date = datetime.strptime(date,'%Y-%m-%d') 
   
    answer = dateDict[datetime_date.weekday()]
    print(answer)
    return answer

