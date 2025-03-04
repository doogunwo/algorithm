#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    int len1 = str1.size(), len2 = str2.size();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    // DP 점화식 적용
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1])  // 같은 문자라면
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else  // 다른 문자라면
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // 최장 공통 부분 수열의 길이 출력
    cout << dp[len1][len2] << endl;
    return 0;
}
