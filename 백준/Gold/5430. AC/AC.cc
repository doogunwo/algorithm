#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

void solution() {
    string p; // 수행할 함수 (R, D)
    int n;    // 배열에 들어있는 수의 개수
    string s; // [x1,...,xn] 형태의 문자열

    cin >> p >> n >> s;

    deque<int> dq;
    
    // 1. 문자열 파싱: s에서 숫자만 추출하여 deque에 삽입
    string temp = "";
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            temp += s[i];
        } else {
            if (!temp.empty()) {
                dq.push_back(stoi(temp));
                temp = "";
            }
        }
    }

    bool isReverse = false; // 현재 방향 상태
    bool isError = false;   // 에러 발생 여부

    // 2. 명령어 처리
    for (char cmd : p) {
        if (cmd == 'R') {
            isReverse = !isReverse; // 방향만 전환
        } else { // 'D'인 경우
            if (dq.empty()) {
                isError = true;
                break;
            }
            if (isReverse) dq.pop_back();  // 뒤집힌 상태면 뒤에서 제거
            else dq.pop_front();           // 정방향 상태면 앞에서 제거
        }
    }

    // 3. 결과 출력
    if (isError) {
        cout << "error\n";
    } else {
        cout << "[";
        if (isReverse) { // 역방향 출력
            while (!dq.empty()) {
                cout << dq.back();
                dq.pop_back();
                if (!dq.empty()) cout << ",";
            }
        } else { // 정방향 출력
            while (!dq.empty()) {
                cout << dq.front();
                dq.pop_front();
                if (!dq.empty()) cout << ",";
            }
        }
        cout << "]\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solution();
    }
    return 0;
}