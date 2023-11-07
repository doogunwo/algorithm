#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers(5);

    for (int i = 0; i < 5; i++) {
        std::cin >> numbers[i];
    }

    int result = 1;
    int count = 0;

    while (true) {
        count = 0;
        for (int i = 0; i < 5; i++) {
            if (result % numbers[i] == 0) {
                count++;
            }
        }
        if (count >= 3) {
            break;
        }
        result++;
    }

    std::cout << result << std::endl;

    return 0;
}
