#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    
    // n을 뒤집은 숫자를 구하기
    while (n > 0) {
        answer.push_back(n % 10);
        n /= 10;
    }
    
    return answer;
}