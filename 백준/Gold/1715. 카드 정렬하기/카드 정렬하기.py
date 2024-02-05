import sys
import heapq


n = int(sys.stdin.readline())
ns = []
for _ in range(n):
    heapq.heappush(ns, int(sys.stdin.readline()))

if len(ns) == 1:
    print(0)
else:
    ans = 0
    while len(ns) > 1:
        temp1 = heapq.heappop(ns)
        temp2 = heapq.heappop(ns)
        ans += temp1 + temp2
        heapq.heappush(ns, temp1 + temp2)
    print(ans)
