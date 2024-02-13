#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, total_water, leaf_cnt;
vector<int> edge[500'001];
bool visited[500'001];

//리프 노드의 갯수 구하기
void bfs() {
	int cur, num_edge, next;
	queue<int> q;
	q.push(1);
	visited[1] = 1;

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		num_edge = edge[cur].size();
		if (cur == 1) num_edge++;
		
		if (num_edge == 1) {
			leaf_cnt++;
			continue;
		}

		for (int i = 0; i < edge[cur].size(); i++) {
			next = edge[cur][i];
			if (visited[next]) continue;
			q.push(next);
			visited[next] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int node1, node2;
    
	cin >> n >> total_water;
	for (int i = 0; i < n - 1; i++) {
		cin >> node1 >> node2;
        //양방향 간선이므로
		edge[node1].push_back(node2);
		edge[node2].push_back(node1);
	}
    
	bfs();
    
	cout.precision(6);
	cout << fixed << (double)total_water / leaf_cnt;
	return 0;
}