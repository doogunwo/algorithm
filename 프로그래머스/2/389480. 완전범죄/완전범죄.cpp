#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
A,B 도둑 팀 모든 물건 훔치기 , 두 도둑 둘다 흔적을 최소화
물건 i 
-> A 도둑이 훔치면 info[i][0]
-> B 도둑이 훔치면 info[i][1] 의 흔적

각 물건에 대해 남기는 흔적은 1~3

경찰에 붙잡히는 조건은 
A도둑 -> 누적 흔적 n개 이상
B 도둑도 누적 흔적 m개  이상

두 도둑 모두 경찰에 붙잡히지 않도록 모든 물건을 훔쳤을 때, A도둑이 남긴 흔적의 누적 개수의 최솟값을 return 

info[i]는 물건 i를 훔칠 때 생기는 흔적의 개수를 나타내며,
[A에 대한 흔적 개수, B에 대한 흔적 개수]의 형태입니다.
*/
/*

동적 계획법 -> 2차원 DP 테이블
DP 테이블
점화식 
dp[i][j] = dp[i-1][j]
dp[i][j] = max(dp[i][j], dp[i-1][j-b_i] + a_i)
dp[i][j] = max(dp[i][j], dp[i-1][j-a_i] + b_i)

*/

const int MAX = 120 + 12;
bool dp[MAX][MAX];

int solution(std::vector<std::vector<int>> info, int n, int m) {
   
  int itemCnt = info.size();
  dp[0][0] = true;

  for(int i=0; i<itemCnt; i++){
    bool nextDp[MAX][MAX]= {false,};
    int traceA = info[i][0];
    int traceB = info[i][1];

    for(int a=0; a<n; a++){
      for(int b=0; b<m; b++){
        if(!dp[a][b])   continue;
        if(a+traceA <n) nextDp[a+traceA][b] = true;
        if(b+traceB <m) nextDp[a][b+traceB] = true;
      }
    }
  

  for(int a= 0; a<n; a++){
    for(int b=0; b<m; b++){
      dp[a][b] = nextDp[a][b];;
      }
    }
  }

  for(int a=0; a<n; a++){
    for(int b= 0; b<m; b++){
      if(dp[a][b])return a;
    }
  }
   
  return -1;
   
   
   
   
   
   
   
}