



cnt2 = 1 

while 1:
    

    l,p,v = map(int,input().split())

    if l==0 and p==0 and v==0: break

    
    res = l*(v//p)
    res = res + min ( v%p , l)
    
    

    
    print('Case %d: %d' %(cnt2,res))
    cnt2 = cnt2+1


    

