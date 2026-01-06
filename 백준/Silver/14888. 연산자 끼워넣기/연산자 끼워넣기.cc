/*
실버1
백트래킹, 브루트포스
*/
#include <iostream>
#include <vector>
using namespace std;

int max_result = -1000000001;
int min_result = 1000000001;

vector<int> s;
vector<int> op(4);

int N;

void dfs(int idx, int current_result){
    if(idx == N) {
        //연산자 다씀
        if(current_result > max_result) max_result = current_result;
        if(current_result < min_result) min_result = current_result;
        return;
    }

    for(int i=0; i<4; i++){
        if(op[i] > 0){
            op[i]--;
            //모든 빈칸마다 4가지 연산자를 다 시도해보는 역할
            if(i==0) dfs(idx+1, current_result+s[idx]);
            else if(i==1) dfs(idx+1, current_result-s[idx]);
            else if(i==2) dfs(idx+1, current_result*s[idx]);
            else if(i==3) dfs(idx+1, current_result/s[idx]);   
            
            op[i]++;
        }
    }
}

int main(){
    cin >> N;

    s.assign(N,0);

    for(int i=0; i<N; i++){
        cin >> s[i];
    }
    
    for(int i=0; i<4; i++){
        // + - x %
        cin >> op[i];
    }

    dfs(1, s[0]);
    cout << max_result << "\n" << min_result << endl;
    return 0;   
}