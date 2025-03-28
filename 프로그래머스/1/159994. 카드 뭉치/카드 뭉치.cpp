#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    unordered_set<string> set1(cards1.begin(), cards1.end());
    unordered_set<string> set2(cards2.begin(), cards2.end());

    int idx1 = 0, idx2 = 0;
    for (const string& word : goal) {
        if (idx1 < cards1.size() && cards1[idx1] == word) idx1++;
        else if (idx2 < cards2.size() && cards2[idx2] == word) idx2++;
        else return "No";
    }
    return "Yes";

}
