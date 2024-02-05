#include <iostream>
#include <vector>
int main(){
    int n, m;
    
    // n과 m 값을 입력받음
    std::cin >> n >> m;
    std::vector<int> circle(n);
    std::vector<int> result;

    // 원형 큐 초기화
    for (int i = 0; i < n; i++) {
        circle[i] = i + 1;
    }

    int index = 0; // 제거될 원소의 인덱스
    while (!circle.empty()) {
        index = (index + m - 1) % circle.size(); // m번째 원소를 찾기 위한 인덱스 계산
        result.push_back(circle[index]); // 결과 벡터에 m번째 원소 추가
        circle.erase(circle.begin() + index); // m번째 원소 제거
    }

    // 결과 출력
    std::cout << "<";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) std::cout << ", ";
    }
    std::cout << ">" << std::endl;

    return 0;
}
