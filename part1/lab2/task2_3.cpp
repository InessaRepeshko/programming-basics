#include <iostream>

int main() {
    int x, n, y = 1;

    std::cout << "Please, enter integer value for variable X, N separated by space: ";
    std::cin >> x >> n;

    if (n <= 0) {
        std::cerr << "Runtime Error! Value of variable n must be greater than 0." << std::endl;
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        y *= (i % 2 == 0)
                ? x - i
                : x + i;
    }

    printf("Result: y = %d \n", y);
    return 0;
}
