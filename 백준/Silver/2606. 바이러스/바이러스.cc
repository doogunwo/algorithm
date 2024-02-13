#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int bfs(vector<int>* graph, int N) {
    vector<bool> visited(N + 1, false);
    int count = 0;

    queue<int> q;
    q.push(1); // 1번 컴퓨터부터 시작

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (!visited[node]) {
            visited[node] = true;
            count++;

            for (int i = 0; i < graph[node].size(); i++) {
                int next = graph[node][i];
                if (!visited[next]) {
                    q.push(next);
                }
            }
        }
    }

    return count - 1; // 1번 컴퓨터는 제외
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> graph[N + 1]; // 인접 리스트로 그래프 표현

    for (int i = 0; i < M; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    int result = bfs(graph, N);
    cout << result << endl;

    return 0;
}
