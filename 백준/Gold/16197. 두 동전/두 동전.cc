/*
골드4
그래프이론, 그래프탐색, 너비 우선 탐색
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 987654321;

struct Point {
    int r, c;
};

int n,m;
vector<string> board;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

//나갔는지 확인하는 함수
bool isOut(int r, int c) {
    return (r < 0 || r >= n || c < 0 || c >= m);
}

// 백트래킹 함수 (현재 이동 횟수, 동전1 좌표, 동전2 좌표)
int solve(int cnt, int r1, int c1, int r2, int c2){
    if(cnt >10 ) return INF;

    bool out1 = isOut(r1, c1);
    bool out2 = isOut(r2, c2);
    int res = INF;
    if(out1 && out2) return INF;
    if(out1 || out2) return cnt;

    for (int i = 0; i < 4; i++){

        int nr1 = r1 + dr[i];
        int nc1 = c1 + dc[i];
        int nr2 = r2 + dr[i];
        int nc2 = c2 + dc[i];

        if (!isOut(nr1, nc1) && board[nr1][nc1] == '#') {
            nr1 = r1; nc1 = c1;
        }
        if (!isOut(nr2, nc2) && board[nr2][nc2] == '#') {
            nr2 = r2; nc2 = c2;
        }

        res = min(res, solve(cnt + 1, nr1, nc1, nr2, nc2));
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin >> n >> m;
    board.resize(n);    
    vector<pair<int, int>> coins;

    for (int i = 0; i < n; i++) {
        cin >> board[i];
        for (int j = 0; j < m; j++) {
            // 입력을 받으면서 동전('o')의 위치를 찾음
            if (board[i][j] == 'o') {
                coins.push_back({i, j});
            }
        }
    }

    int result = solve(0, coins[0].first, coins[0].second, coins[1].first, coins[1].second);
    if (result > 10) cout << -1 << endl;
    else cout << result << endl;
    return 0;
}
