#include "iostream"

const int MIN_NUMBER = 0;
const int MAX_NUMBER = 10;

int main() {
    std::cout << "Enter integer between " << MIN_NUMBER << " and " << MAX_NUMBER << ": ";
    int n;

    std::cin >> n;

    if (n < MIN_NUMBER || n > MAX_NUMBER) {
        std::cerr << "Error!" << std::endl;
        return 1;
    }

    for(int i = MIN_NUMBER; i <= n; i++) {
        std::cout << "8 ^ " << i << " = " << (1 << 3 * i) << std::endl;
    }

    return 0;
}

