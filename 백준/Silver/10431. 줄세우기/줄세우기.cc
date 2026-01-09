/*
줄세우기
실버5
정렬,구현
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int P;
    cin >> P;

    while (P--) {
        int T;
        cin >> T;

        vector<int> a(20);
        for (int i = 0; i < 20; i++) cin >> a[i];

        int moves = 0;
        // inversion count
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < i; j++) {
                if (a[j] > a[i]) moves++;
            }
        }

        cout << T << " " << moves << "\n";
    }
    return 0;
}
