#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        // 공백 출력
        for (int j = 0; j < i; ++j) {
            cout << " ";
        }
        // 별 출력
        for (int k = 0; k < n - i; ++k) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
