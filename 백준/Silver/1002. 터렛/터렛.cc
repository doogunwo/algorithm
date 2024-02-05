#include <stdio.h>
#include <math.h>

int main(void)
{
    int t, x1, y1, r1, x2, y2, r2, result;
    double distanse, subtract;    //거리, 뺄셈
    scanf("%d", &t);
    
    while(t--)
    {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        distanse = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));    //(x1, y1)와 (x2, y2)의 거리
        subtract = r1 > r2 ? r1 - r2 : r2 - r1;
        
        if(distanse == 0 && r1 == r2) result = -1;    //두 원이 완전히 일치하는 경우
        else if(distanse < r1 + r2 && (subtract < distanse)) result = 2;    //두 원의 교점이 2개일 경우
        else if(distanse == r1 + r2 || distanse == subtract) result = 1;    //두 원의 교점이 1개일 경우
        else result = 0;    //두 원의 교점이 없을 경우
        
        printf("%d\n", result);
    }
}


