#include <bits/stdc++.h>
using namespace std;
string s, t;
int ans = 0;
/*

1. s에서 t로 만든다면 매 문자에 대해 2가지 경우의 수를 확인해야 하므로 2^50시간복잡도를 가지게 됩니다. 
이는 시간초과로 틀리게 됩니다. 2. 반대로 t에서 s를 만드는 생각을 해야 합니다. 때문에 명령어는 다음처럼 바뀌게 됩니다. 
 2-1. 문자열 뒤에 A를 뺸다.  2-2. 문자열을 뒤집고 B를 뺸다.3. dfs 함수를 수행합니다. 

*/
int dfs(string tmp){
    if(tmp == s) return 1;
    if(s.size() > tmp.size()) return 0;

    int ans = 0;

    if(tmp[tmp.size() - 1] == 'A'){
        tmp.pop_back();
        ans = max(ans,dfs(tmp));
        tmp.push_back('A');
    }
    if(tmp[0] == 'B'){
        reverse(tmp.begin(), tmp.end());
        tmp.pop_back();
        ans = max(ans, dfs(tmp));
    }
    return ans;
}

int main(){
    cin >> s >> t;
    cout << dfs(t);
}