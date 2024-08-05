#include <iostream>
#include <vector>
#include <algorithm> // std::max_element
using namespace std;

int main() {
    vector<int> numbers(9);

    // 9개의 숫자를 입력받음
    for (int i = 0; i < 9; i++) {
        cin >> numbers[i];
    }

    // 최대값의 반복자를 찾음
    auto maxIt = max_element(numbers.begin(), numbers.end());
    int maxIndex = distance(numbers.begin(), maxIt);
    // 최대값과 그 인덱스 출력
    cout << *maxIt << endl << maxIndex + 1 << endl;

    return 0;
}
