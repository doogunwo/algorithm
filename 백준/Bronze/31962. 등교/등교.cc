#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    int latestDeparture = -1; // 지각하지 않고 탈 수 있는 버스 중 가장 늦은 출발 시간을 저장할 변수

    for (int i = 0; i < n; ++i) {
        int s, t;
        cin >> s >> t;

        if (s + t <= x) { // 학교에 지각하지 않고 도착할 수 있는지 확인
            if (s > latestDeparture) { // 가장 늦게 출발하는 버스 찾기
                latestDeparture = s;
            }
        }
    }

    cout << latestDeparture << endl;

    return 0;
}
