#include <iostream>
using namespace std;

int main() {
    uint64_t N;
    cin >> N;

    int K = 64;

    while (N % 2 == 0) {
        N /= 2;
        K--;
    }

    cout << K << endl;
    return 0;
}
