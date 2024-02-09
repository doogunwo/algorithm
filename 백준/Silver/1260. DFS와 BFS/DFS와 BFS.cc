#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;



void dfs(int node, vector<vector<int> >& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << node << ' ';

    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next, graph, visited);
        }
    }
}

void bfs(int start, vector<vector<int> >& graph, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';

        for (int next : graph[cur]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}



int main(){

    int n,m,v;
    cin>>n>>m>>v;
    vector< vector<int> > graph(n+1);
    vector<bool> visited(n + 1, false);

    for(int i=0; i<m; i=i+1){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(v, graph, visited);
    cout << '\n';

    fill(visited.begin(), visited.end(), false);
    bfs(v, graph, visited);
    cout << '\n';

    return 0;

}