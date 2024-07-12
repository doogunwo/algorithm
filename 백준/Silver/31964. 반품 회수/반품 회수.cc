#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int simulate(int n, vector<int>& X, vector<int>& T) {
    int ret = X[n - 1]; // 마지막 집까지 가는 시간

    for (int i = n - 1; i >= 0; --i) {
        if (i != n - 1) {
            ret += X[i + 1] - X[i]; // 오른쪽 집에서 현재 집으로 이동 시간 추가
        }
        if (ret < T[i]) {
            ret = T[i]; // 현재 시간이 해당 집의 물건 내놓는 시간보다 작으면 기다림
        }
    }

    ret += X[0]; // 마지막으로 출발지점으로 돌아오는 시간 추가

    return ret;
}

int main() {
    int n;
    cin >> n;

    vector<int> X(n);
    vector<int> T(n);

    for (int i = 0; i < n; ++i) {
        cin >> X[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> T[i];
    }

    cout << simulate(n, X, T) << endl;

    return 0;
}
