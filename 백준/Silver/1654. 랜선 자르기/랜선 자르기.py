k,n = input().split()

LAN_cables = [int(input()) for i in range(int(k))]

start = 1
end = max(LAN_cables)

while(start <= end):
    mid = (start+end) // 2
   
    total = sum(cable//mid for cable in LAN_cables)
    
    if total>=int(n):
        start = mid +1
    else:
        end = mid -1

print(end)



