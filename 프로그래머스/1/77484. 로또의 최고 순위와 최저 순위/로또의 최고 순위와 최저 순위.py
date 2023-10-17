def solution(lottos, win_nums):
    rank = {6:1,5:2,4:3,3:4,2:5,1:6,0:6}
    ans = 0
    cntZero = lottos.count(0)
    for i in lottos:
        if i in win_nums:
            ans = ans +1
    maxRank = ans + cntZero
  
    return rank[maxRank],rank[ans]