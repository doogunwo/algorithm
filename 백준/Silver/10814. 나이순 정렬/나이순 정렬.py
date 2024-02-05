N = int(input())
#words.sort(key=lambda x: (len(x), x))
mans = []
for _ in range(N):
    
    age, name = input().split()
    mans.append((int(age),name))

mans.sort(key=lambda x: x[0])

for man in mans:
    print(man[0],man[1])
