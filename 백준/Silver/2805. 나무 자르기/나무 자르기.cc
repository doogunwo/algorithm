#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> tree(n);
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }

    int start = 0;
    int end = *max_element(tree.begin(), tree.end());
    int result = 0;

    while (start <= end) {
        int mid = (start + end) / 2;
        long long total = 0;

        for (int t : tree) {
            if (t > mid) {
                total += (t - mid);
            }
        }

        if (total >= m) {
            result = mid;        // 조건 만족 → 높이 더 올려볼 수 있음
            start = mid + 1;
        } else {
            end = mid - 1;       // 너무 많이 잘랐음 → 높이 낮춰야
        }
    }

    cout << result << '\n';
    return 0;
}
