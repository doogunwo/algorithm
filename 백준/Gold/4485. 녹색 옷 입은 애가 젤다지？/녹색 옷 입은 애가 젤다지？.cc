#include <iostream>
#include <vector>
#include <queue>
#include <utility>

const int INF = 987654321;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

struct Node {
    int x,y, cost;
    Node(int _x, int _y, int _cost) : x(_x) , y(_y), cost(_cost) {}
    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

int sol(std::vector<std::vector<int>>& cave){
    int result = 0; 
    int N= cave.size();

    std::vector<std::vector<int>> dist(N, std::vector<int>(N, INF));
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;

    dist[0][0] = cave[0][0];
    pq.push(Node(0, 0, cave[0][0]));

    while(!pq.empty()){
        Node curr = pq.top();
        pq.pop();

        int x = curr.x;
        int y = curr.y;
        int cost = curr.cost;

        if (cost > dist[x][y]) continue;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            // 범위를 벗어나면 무시
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            // 다음 노드까지의 비용 갱신
            int next_cost = cost + cave[nx][ny];
            if (next_cost < dist[nx][ny]) {
                dist[nx][ny] = next_cost;
                pq.push(Node(nx, ny, next_cost));
            }
        }
    }
    

    return dist[N - 1][N - 1];
}

int main(){

    int cnt = 0;
    while (1)
    {   
        
        int  n;
        std::cin >> n;
        if(n==0){
            break;
        }
        else{
            cnt = cnt +1;
            std::vector<std::vector<int>> v(n, std::vector<int>(n));\
            for(int row = 0; row < n; row++) {
                for(int col = 0; col < n; col++) {
                    std::cin >> v[row][col]; // 행렬 요소 입력
                }
            }
            int result = sol(v);
            std::cout << "Problem " << cnt << ": " << result << std::endl;
        }

    }
    


    return 0;


}