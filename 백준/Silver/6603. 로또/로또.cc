#include <iostream>
#include <vector>

using namespace std;

int K;
vector<int> S;
int result[6]; // 선택된 6개의 숫자를 저장할 배열

// 조합을 찾는 백트래킹 함수
void dfs(int start, int depth) {
    // 6개를 모두 선택한 경우 (탈출 조건)
    if (depth == 6) {
        for (int i = 0; i < 6; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }

    // start 인덱스부터 K-1까지 탐색
    for (int i = start; i < K; i++) {
        result[depth] = S[i]; // 숫자 선택
        dfs(i + 1, depth + 1); // 다음 숫자를 선택하기 위해 재귀 호출 (i+1)
    }
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> K;
        if (K == 0) break; // 0이 입력되면 종료

        S.assign(K, 0); // 벡터 크기를 K로 맞추고 초기화
        for (int i = 0; i < K; i++) {
            cin >> S[i];
        }

        // 조합 탐색 시작 (0번 인덱스부터, 0개 선택됨)
        dfs(0, 0);

        // 각 테스트 케이스 사이에 빈 줄 출력
        cout << "\n";
    }

    return 0;
}