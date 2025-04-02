#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> direction = {{0,1}, {0,-1}, {1,0}, {-1,0}};

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));  // 방문 체크
    queue<pair<int, int>> q;
    
    vector<vector<int>> dist(n, vector<int>(m, 0));  // 거리 저장

    q.push({0, 0});
    visited[0][0] = true;
    dist[0][0] = 1;  // 시작점 거리 = 1

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (auto& d : direction) {
            int nx = x + d[0];
            int ny = y + d[1];

            // 유효한 위치인지 + 갈 수 있는 곳인지 + 방문 안 한 곳인지
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (maps[nx][ny] == 1 && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[x][y] + 1;  // 이전 거리 + 1
                    q.push({nx, ny});
                }
            }
        }
    }

    // 도착점까지 도달했으면 거리 리턴, 못 갔으면 -1
    return dist[n-1][m-1] == 0 ? -1 : dist[n-1][m-1];
}
