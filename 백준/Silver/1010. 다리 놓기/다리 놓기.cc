#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, n, m, t, r;
    long long int numerator;
    long long int denominator;
    long int *result;
    
    scanf("%d", &t);
    result = (long int*)malloc(sizeof(long int)*t);
    
    for (i=0; i<t; i++)
    {
        result[i] = 0;
        numerator = 1, denominator = 1;
        scanf("%d %d", &n, &m);
        
        if(m-n < n)
            n = m-n; 
        for (j=0; j<n; j++) {
            numerator *= m; 
            m -= 1; //분자
        }
        for (j=n; j>0; j--)
            denominator *= j; //분모
        result[i] = numerator / denominator;
    }
    
    for(i=0; i<t; i++)
        printf("%ld\n", result[i]); //long int 형은 %ld
    
    free(result);
    
    return 0;
}