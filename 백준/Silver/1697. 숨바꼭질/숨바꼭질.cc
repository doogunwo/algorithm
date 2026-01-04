#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100001;
int dist[MAX];


int main(){
    int N, K;
    cin >> N >> K;

    for(int i=0; i<MAX; i++){
        dist[i] = -1;
    }

    queue<int> q;
    q.push(N);
    dist[N] = 0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        if(curr == K){
            cout << dist[curr] << endl;
            break;
        }

        int next_steps[3] = {curr -1, curr+1, curr*2};
        for(int next : next_steps){
            if(next >= 0 && next < MAX && dist[next] == -1 ){
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
}