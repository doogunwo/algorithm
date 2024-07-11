#include <iostream>
#include <vector>
#include <cstring> // for memset

using namespace std;

vector<vector<int>> graph;
bool visited[501];
bool isTree;
int nodes, edges;

void dfs(int node, int parent) {
    visited[node] = true;
    nodes++;
    for (int next : graph[node]) {
        if (!visited[next]) {
            edges++;
            dfs(next, node);
        } else if (next != parent) {
            isTree = false;
        }
    }
}

int main() {
    int caseNum = 1;
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        graph.assign(n + 1, vector<int>());
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int treeCount = 0;

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                isTree = true;
                nodes = 0;
                edges = 0;
                dfs(i, -1);

                if (isTree && edges == nodes - 1) {
                    treeCount++;
                }
            }
        }

        cout << "Case " << caseNum << ": ";
        if (treeCount == 0) {
            cout << "No trees." << endl;
        } else if (treeCount == 1) {
            cout << "There is one tree." << endl;
        } else {
            cout << "A forest of " << treeCount << " trees." << endl;
        }
        caseNum++;
    }

    return 0;
}
