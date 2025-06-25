// 두 사람이 선물을 주고받았습니다.
// 이번달기록으로 다음달누가 선물을 가장 많이 받을지 예측하려고 합니다. 
// "muzi frodo" 는 gift 명단의 양식이다. A-B 구조이고 A->B 선물을 준 것이다.
// A와 B는 friends의 원소이며, 이를 토대로
// 결과 출력으로 선물 지수 정리하여 가장 많이 선물을 받을 친구를 구하자.
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string,int> names;
int BOARD[51][51];
int people[51];

using namespace std;


int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0 ;
    for(int i=0; i<friends.size(); i++){
        string name = friends[i];
        names[name] = i;
    }

    for(int i=0; i<gifts.size(); i++){
        string tg = gifts[i];
        int find_space = tg.find(' ');
        string from_friend  = tg.substr(0, find_space);
        string to_friend    = tg.substr(find_space+1);

        int fIdx = names[from_friend];
        int tIdx = names[to_friend];

        BOARD[fIdx][tIdx]++;
        people[fIdx]++;
        people[tIdx]--;
       
    }

    for(int i=0; i<friends.size(); i++){
        int ret = 0;
        int maxGift = -1;
        int y,x;

        for(int j=0; j<friends.size(); j++){
            if(i==j) continue;
            if(BOARD[i][j] > BOARD[j][i]) ret ++;
            if(BOARD[i][j] == BOARD[j][i]){
                if(people[i] > people[j]) ret++;
            }
        }
        answer = max(answer, ret);
    }
    return answer;
}