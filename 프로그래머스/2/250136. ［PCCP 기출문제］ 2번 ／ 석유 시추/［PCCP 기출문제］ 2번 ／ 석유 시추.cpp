#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int>> direction = {{0,1}, {0,-1}, {1,0}, {-1,0}};

int solution(vector<vector<int>> land) {
    int n = land.size();       // 행 수
    int m = land[0].size();    // 열 수

    vector<vector<int>> groupMap(n, vector<int>(m, -1));  // 그룹 번호 저장
    unordered_map<int, int> groupSizeMap;  // 그룹 번호 -> 석유량

    int groupId = 0;

    // BFS로 그룹 구분
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (land[i][j] == 1 && groupMap[i][j] == -1) {
                int oilCount = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                groupMap[i][j] = groupId;

                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    oilCount++;

                    for (auto& d : direction) {
                        int nx = x + d[0];
                        int ny = y + d[1];

                        if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                            if (land[nx][ny] == 1 && groupMap[nx][ny] == -1) {
                                groupMap[nx][ny] = groupId;
                                q.push({nx, ny});
                            }
                        }
                    }
                }

                groupSizeMap[groupId] = oilCount;
                groupId++;
            }
        }
    }

    // 각 열마다 시추했을 때 얻을 수 있는 석유량 계산
    int maxOil = 0;
    for (int col = 0; col < m; col++) {
        int totalOil = 0;
        vector<bool> visited(groupId, false);

        for (int row = 0; row < n; row++) {
            int gId = groupMap[row][col];
            if (gId != -1 && !visited[gId]) {
                visited[gId] = true;
                totalOil += groupSizeMap[gId];
            }
        }

        maxOil = max(maxOil, totalOil);
    }

    return maxOil;
}
