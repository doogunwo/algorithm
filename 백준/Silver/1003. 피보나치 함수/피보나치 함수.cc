#include <iostream>
 
int fibonacci(int n) {
    static int mem[41] = { 0 };
    if (mem[n] > 0) return mem[n];
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    return mem[n] = fibonacci(n - 2) + fibonacci(n - 1);
}
 
 
int main() {
    int T, N;
    scanf("%d", &T);
 
    for (int i = 0; i < T; ++i) {
        scanf("%d", &N);
        if (N == 0) printf("1 0\n");
        else printf("%d %d\n", fibonacci(N - 1), fibonacci(N));
    }
 
    return 0;
}