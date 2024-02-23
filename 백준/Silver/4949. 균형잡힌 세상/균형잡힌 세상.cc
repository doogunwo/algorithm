#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string& str) {
    stack<char> s;
    for (char ch : str) {
        if (ch == '(' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == ']') {
            if (s.empty()) return false;
            char top = s.top();
            if ((ch == ')' && top == '(') || (ch == ']' && top == '[')) {
                s.pop();
            } else {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        string str;
        getline(cin, str);
        if (str == ".") break;
        if (isBalanced(str)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}
