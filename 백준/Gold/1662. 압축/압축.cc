#include <bits/stdc++.h>
#define MAX 51
using namespace std;
 
char S[MAX];
int len[MAX], K[MAX];
// len: 숫자 길이 저장 배열, K: 괄호 앞 숫자
// 몇 겹의 괄호인지에 따라 index 배정
// 괄호에 포함되지 않은 가장 바깥 숫자면 index = 0, 한 겹의 괄호 안에 있는 수는 index = 1, ...  
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> S;
	int i, cur = 0, num = 0, size = strlen(S);
	for (i = 0; i < size; i++) {
		if (S[i] == '(') {
			len[cur]--;	// 괄호 앞의 K는 길이에 포함시키지 않으므로
			cur++;
			K[cur] = num;	// 아래 else 문에서 저장한 숫자를 괄호 앞 숫자로 확정
		}
		else if (S[i] == ')') {
			int temp = len[cur] * K[cur];
			len[cur] = 0;	// 해당 괄호는 끝났으므로 0으로 초기화
			cur--;
			len[cur] += temp;
		}
		else {
			len[cur]++;
			num = S[i] - '0';	// 괄호 앞 숫자일 수 있으므로 일단 저장
		}
	}
	cout << len[0];
}