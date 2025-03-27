#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    int count = 0;
    int removed_zeros = 0;

    while (s != "1") {
        int zero_count = 0;
        string ones_only = "";

        // 0 제거 및 개수 세기
        for (char c : s) {
            if (c == '0') zero_count++;
            else ones_only += c;
        }

        removed_zeros += zero_count;
        int len = ones_only.length();

        // 길이를 이진수로 변환
        s = "";
        while (len > 0) {
            s = to_string(len % 2) + s;
            len /= 2;
        }

        count++;
    }

    return {count, removed_zeros};
}