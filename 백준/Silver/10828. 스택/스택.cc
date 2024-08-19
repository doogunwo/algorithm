#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> v;  // 스택 역할을 하는 벡터
    
    for (int i = 0; i < N; ++i) {
        string command;
        cin >> command;
        
        if (command == "push") {
            int x;
            cin >> x;
            v.push_back(x);
        } else if (command == "pop") {
            if (v.empty()) {
                cout << "-1" << endl;
            } else {
                cout << v.back() << endl;
                v.pop_back();
            }
        } else if (command == "size") {
            cout << v.size() << endl;
        } else if (command == "empty") {
            cout << v.empty() << endl;
        } else if (command == "top") {
            if (v.empty()) {
                cout << "-1" << endl;
            } else {
                cout << v.back() << endl;
            }
        }
    }
    
    return 0;
}
