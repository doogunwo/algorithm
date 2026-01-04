/*

$i$번째 집을 빨강으로 칠할 때의 최소 비용:
DP[i][0] = min(DP[i-1][1], DP[i-1][2]) + Cost[i][0]
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 1000 * 1000 + 1;

int main(){
    int N;
    cin >> N;

    vector<vector<int>> cost(N+1, vector<int>(3));
    for (int i = 1; i <= N; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    
    int min_total_cost = INF;

    for(int start_color = 0; start_color <= 2; start_color++){
        vector<vector<int>> dp(N + 1, vector<int>(3));

        for(int i =0; i<=2 ; i++){
            if(i==start_color) dp[1][i] = cost[1][i];
            else dp[1][i] = INF;
        }

        for (int i = 2; i <= N; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
        }

        for (int last_color = 0; last_color <= 2; last_color++) {
            if (last_color == start_color) continue; // 조건: 1번 집 != N번 집
            min_total_cost = min(min_total_cost, dp[N][last_color]);
        }

    }
    cout << min_total_cost << endl;

}
