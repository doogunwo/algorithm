def solution(participant, completion):
    
    hashDict = {}
    sumHash = 0

    for part in participant:
        hashDict[hash(part)] = part
        sumHash = sumHash + hash(part)
    
    for comp in completion:
        sumHash = sumHash - hash(comp)

                
    return hashDict[sumHash]
