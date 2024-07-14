#include <iostream>
using namespace std;

int main() {
    int t; // 테스트 케이스 수
    cin >> t;

    while (t--) {
        int n, m; // 국가의 수와 항공로의 수
        cin >> n >> m;

        // 항공로의 정보는 실제로 필요하지 않습니다.
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
        }

        // 최소 간선의 수는 국가의 수 - 1
        cout << n - 1 << endl;
    }

    return 0;
}
