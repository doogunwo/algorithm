#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Piece {
    int x, y, direction;
};

int N, K;
int chesspan[13][13];
// 각 칸에 쌓인 말들의 번호를 저장 (바닥부터 순서대로)
vector<int> state[13][13];
vector<Piece> pieces;

// 방향: 1:→, 2:←, 3:↑, 4:↓ (문제의 인덱스와 맞춤)
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

// 방향 전환 (반대 방향)
int reverseDir(int d) {
    if (d == 1) return 2;
    if (d == 2) return 1;
    if (d == 3) return 4;
    return 3;
}

int solve() {
    for (int turn = 1; turn <= 1000; turn++) {
        for (int i = 0; i < K; i++) {
            int x = pieces[i].x;
            int y = pieces[i].y;
            int dir = pieces[i].direction;

            // 1. 가장 밑에 있는 말인지 확인 (핵심 조건)
            if (state[x][y][0] != i) continue;

            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // 2. 파란색이거나 범위를 벗어나는 경우
            if (nx < 0 || nx >= N || ny < 0 || ny >= N || chesspan[nx][ny] == 2) {
                // 방향 반대로
                pieces[i].direction = reverseDir(dir);
                int ndir = pieces[i].direction;
                nx = x + dx[ndir];
                ny = y + dy[ndir];

                // 반대 방향으로 한 칸 갔을 때도 파란색/범위 밖이면 이동 안 함
                if (nx < 0 || nx >= N || ny < 0 || ny >= N || chesspan[nx][ny] == 2) continue;
            }

            // 3. 이동할 칸이 흰색 또는 빨간색인 경우
            vector<int> &current_stack = state[x][y];
            vector<int> &next_stack = state[nx][ny];

            // 빨간색이면 순서 뒤집기
            if (chesspan[nx][ny] == 1) {
                reverse(current_stack.begin(), current_stack.end());
            }

            // 말 이동 (현재 스택의 모든 말을 다음 칸으로)
            for (int piece_idx : current_stack) {
                pieces[piece_idx].x = nx;
                pieces[piece_idx].y = ny;
                next_stack.push_back(piece_idx);
            }
            current_stack.clear();

            // 4. 말이 4개 이상 쌓였는지 즉시 확인
            if (next_stack.size() >= 4) return turn;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> chesspan[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        int r, c, d;
        cin >> r >> c >> d;
        // 0-indexed로 변환하여 저장
        pieces.push_back({r - 1, c - 1, d});
        state[r - 1][c - 1].push_back(i);
    }

    cout << solve() << endl;

    return 0;
}