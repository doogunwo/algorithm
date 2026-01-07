#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct pos {
    int x;
    int y;
};

// 전역 변수로 설정하여 함수 간 공유를 쉽게 합니다.
vector<pos> store; // 치킨집들의 위치
vector<pos> home;  // 집들의 위치
vector<pos> selected; // 선택된 M개의 치킨집
int N, M;
int ans = 1e9; // 최종 정답 (최소 도시 치킨 거리)

// 현재 선택된 치킨집들(selected)을 기준으로 도시의 치킨 거리를 계산하는 함수
void calculate_city_distance() {
    int total_city_dist = 0;

    for (int i = 0; i < home.size(); i++) {
        int min_dist_for_this_home = 1e9;
        for (int j = 0; j < selected.size(); j++) {
            // 맨해튼 거리 계산
            int dist = abs(home[i].x - selected[j].x) + abs(home[i].y - selected[j].y);
            min_dist_for_this_home = min(min_dist_for_this_home, dist);
        }
        total_city_dist += min_dist_for_this_home;
    }
    // 전체 조합 중 가장 작은 값을 저장
    ans = min(ans, total_city_dist);
}

// 백트래킹으로 치킨집 조합을 구하는 함수
void dfs(int start, int count) {
    // M개를 모두 선택했다면 거리 계산
    if (count == M) {
        calculate_city_distance();
        return;
    }

    // 조합(Combination) 구현: start부터 시작해서 중복 없이 선택
    for (int i = start; i < store.size(); i++) {
        selected.push_back(store[i]); // 선택
        dfs(i + 1, count + 1);        // 다음 단계 진입
        selected.pop_back();          // 선택 취소 (복구)
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    // 사용자님의 입력 로직 유지 (오타 수정 포함)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            if (temp == 2) {
                pos p;
                p.x = i;
                p.y = j;
                store.push_back(p);
            } else if (temp == 1) {
                pos p;
                p.x = i;
                p.y = j;
                home.push_back(p); // store가 아닌 home에 저장하도록 수정
            }
        }
    }

    // 0번 치킨집부터 시작해서 M개를 뽑는 조합 탐색 시작
    dfs(0, 0);

    cout << ans << endl;

    return 0;
}