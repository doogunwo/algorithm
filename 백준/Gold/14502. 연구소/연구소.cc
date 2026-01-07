/*
골드4
구현, 그래프 이론, 브루트포스, BFS, 격자 그래프
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Map;
vector<pair<int,int>> virus_position;

void get_virus_position() {
    virus_position.clear();
    int N = (int)Map.size();
    int M = N ? (int)Map[0].size() : 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (Map[i][j] == 2) virus_position.emplace_back(i, j);
        }
    }
}

int spread_and_count_safe(vector<vector<int>> temp) {
    int N = (int)temp.size();
    int M = N ? (int)temp[0].size() : 0;

    queue<pair<int,int>> q;
    for (auto &p : virus_position) q.push(p);

    static const int dx[4] = {1, -1, 0, 0};
    static const int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (temp[nx][ny] == 0) {
                temp[nx][ny] = 2;
                q.emplace(nx, ny);
            }
        }
    }

    int safe = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (temp[i][j] == 0) ++safe;

    return safe;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    Map.assign(N, vector<int>(M));
    vector<pair<int,int>> empty_pos;
    empty_pos.reserve(N * M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Map[i][j];
            if (Map[i][j] == 0) empty_pos.emplace_back(i, j);
        }
    }

    get_virus_position();

    int ans = 0;
    int E = (int)empty_pos.size();

    // 0인 칸 중 3개를 골라 벽(1) 세우기: 조합 brute-force
    for (int a = 0; a < E; ++a) {
        for (int b = a + 1; b < E; ++b) {
            for (int c = b + 1; c < E; ++c) {
                auto temp = Map;

                auto [ax, ay] = empty_pos[a];
                auto [bx, by] = empty_pos[b];
                auto [cx, cy] = empty_pos[c];

                temp[ax][ay] = 1;
                temp[bx][by] = 1;
                temp[cx][cy] = 1;

                ans = max(ans, spread_and_count_safe(std::move(temp)));
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
