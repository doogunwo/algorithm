#include <iostream>
#include <vector>
#include <algorithm> // sort 사용

using namespace std;

void solve(){
    int N;
    cin >> N;
    
    // long long 사용 필수 (병사 번호가 2^31 이상일 수 있음)
    vector<long long> soldiers(N);
    
    for(int i=0; i<N; i++){
        cin >> soldiers[i];
    }

    // 1. 정렬하기 (O(N log N))
    sort(soldiers.begin(), soldiers.end());

    // 2. 후보 찍기 (과반수가 있다면 무조건 가운데에 있음)
    long long candidate = soldiers[N / 2];

    // 3. 진짜 과반수인지 확인하기 (O(N))
    // 정렬이 되어있으므로 lower_bound, upper_bound로 더 빠르게 셀 수도 있지만
    // 그냥 for문 돌려도 시간 충분함
    int count = 0;
    for(long long s : soldiers){
        if(s == candidate) count++;
    }

    if(count > N / 2) cout << candidate << "\n";
    else cout << "SYJKGW" << "\n";
}

int main(){
    // 입출력 가속 (필수)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int gN;
    cin >> gN;
    while(gN--){
        solve();
    }
    return 0;
}