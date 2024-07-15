#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    deque<int> dq;
    vector<int> targets(M);

    // 덱 초기화
    for (int i = 1; i <= N; ++i) {
        dq.push_back(i);
    }

    // 제거해야 하는 원소들 입력받기
    for (int i = 0; i < M; ++i) {
        cin >> targets[i];
    }

    int operations = 0;

    for (int i = 0; i < M; ++i) {
        int target = targets[i];
        int index = 0;

        // 타겟의 위치를 찾는다
        for (int j = 0; j < dq.size(); ++j) {
            if (dq[j] == target) {
                index = j;
                break;
            }
        }

        // 왼쪽으로 회전하는 것이 더 빠른지, 오른쪽으로 회전하는 것이 더 빠른지 결정
        if (index < dq.size() - index) {
            // 왼쪽으로 회전
            for (int j = 0; j < index; ++j) {
                dq.push_back(dq.front());
                dq.pop_front();
                ++operations;
            }
        } else {
            // 오른쪽으로 회전
            for (int j = 0; j < dq.size() - index; ++j) {
                dq.push_front(dq.back());
                dq.pop_back();
                ++operations;
            }
        }

        // 타겟을 제거
        dq.pop_front();
    }

    cout << operations << endl;

    return 0;
}
