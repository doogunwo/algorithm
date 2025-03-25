#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<bool>> graph(n+1, vector<bool>(n+1 , false));
    for(auto& result : results){
        int win = result[0];
        int lose = result[1];
        graph[win][lose] = true;
    }
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(graph[i][k] && graph[k][j]) graph[i][j] = true;
            }
        }
    }
    
    // 순위 체크 가능한지 
    int answer = 0;
    for(int i=1; i<=n; i++){
        int count = 0;
        for(int j=1; j<=n; j++){
            if(graph[i][j] || graph[j][i]) count ++;
        }
        if(count == n-1) answer ++;
    }
    
    return answer;
    
}