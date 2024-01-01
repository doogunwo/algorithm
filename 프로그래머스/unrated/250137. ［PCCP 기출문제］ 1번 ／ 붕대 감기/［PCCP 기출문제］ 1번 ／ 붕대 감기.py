def isMaxHealth(health, max_health):
    if health>max_health:
        return max_health
    else:
        return health
    
def heal(health, bandage, bandage_count, max_health):
    health+=bandage[1]
    bandage_count+=1
    if(bandage_count==bandage[0]):
        health+=bandage[2]
        bandage_count=0
    health=isMaxHealth(health, max_health)
    return health, bandage_count

def solution(bandage, health, attacks):
    attacks_num=len(attacks)
    last_attacks_time = attacks[attacks_num-1][0]
    max_health=health
    attacks_count=0
    bandage_count=0
    for i in range(1,last_attacks_time+1):
        if attacks[attacks_count][0] == i:
            health-=attacks[attacks_count][1]
            bandage_count=0
            if health <=0:
                health = -1
                break
            attacks_count+=1
        else:
            health, bandage_count = heal(health, bandage, bandage_count, max_health)
    
    return health