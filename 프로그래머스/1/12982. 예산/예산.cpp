#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;

    // 부서별 신청 금액을 오름차순으로 정렬
    sort(d.begin(), d.end());

    for (int i = 0; i < d.size(); i++) {
        // 현재 부서의 신청 금액이 예산 내에 있으면 지원 가능
        if (budget >= d[i]) {
            budget -= d[i]; // 예산에서 차감
            answer++; // 부서 지원 개수 증가
        } else {
            // 예산을 초과하면 더 이상 지원할 수 없음
            break;
        }
    }

    return answer;
}