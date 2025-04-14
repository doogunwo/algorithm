#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    vector<long long> LAN_cables(k);
    for (int i = 0; i < k; ++i) {
        cin >> LAN_cables[i];
    }

    long long start = 1;
    long long end = *max_element(LAN_cables.begin(), LAN_cables.end());
    long long mid, total;
    long long answer = 0;

    while (start <= end) {
        mid = (start + end) / 2;
        total = 0;

        for (long long cable : LAN_cables) {
            total += cable / mid;
        }

        if (total >= n) {
            answer = mid;         // 가능하니 더 길게 잘라보자
            start = mid + 1;
        } else {
            end = mid - 1;        // 너무 길게 잘랐으니 짧게
        }
    }

    cout << answer << endl;
    return 0;
}
