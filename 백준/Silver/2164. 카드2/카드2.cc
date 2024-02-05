#include <iostream>
#include <queue>

int main() {
    int n;
    std::cin >> n;
    std::queue<int> cards;

    // 1부터 n까지 카드를 큐에 삽입
    for (int i = 1; i <= n; ++i) {
        cards.push(i);
    }

    // 큐에 카드가 1장 남을 때까지 반복
    while (cards.size() > 1) {
        cards.pop(); // 맨 위의 카드를 버림
        cards.push(cards.front()); // 그 다음 카드를 맨 뒤로 이동
        cards.pop(); // 이동한 카드를 큐에서 제거
    }

    // 마지막 카드 출력
    std::cout << cards.front() << std::endl;

    return 0;
}
