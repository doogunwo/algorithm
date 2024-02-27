#include <iostream>
#include<string>

#include<queue>
#include<vector>
#include<functional>

using namespace std;
int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	
	priority_queue <int, vector<int>, greater<int>> pq;

	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num >= 1) {
			pq.push(num);
		}
		else if (num == 0) {
			if (pq.empty()) {
				printf("0\n");
			}
			else {
				printf("%d\n",pq.top());
				pq.pop();
			}

		}
	}
	return 0;
}