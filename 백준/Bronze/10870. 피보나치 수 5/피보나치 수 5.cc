#include <iostream>
using namespace std;

// 피보나치 수열을 반복문으로 계산
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int next = a + b;
        a = b;
        b = next;
    }
    return b;
}

int main() {
    int n;
    cin >> n; // 입력 받기
    cout << fibonacci(n) << endl; // n번째 피보나치 수 출력
    return 0;
}
