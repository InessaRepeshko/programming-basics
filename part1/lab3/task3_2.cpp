#include <iostream>

double recursive(double x, int n) {
    if (n == 1) {
        return x + n;
    } else {
        return (x + n) * recursive(x, n - 1);
    }
}

int main() {
    double x;
    int n;

    std::cout << "Enter `X`: ";
    std::cin >> x;

    std::cout << "Enter `N`: ";
    std::cin >> n;

    if (n <= 0) {
        std::cerr << "Error! Variable `n` must be greater than 0." << std::endl;
        return 1;
    }

    std::cout << "Result: " << recursive(x, n);
    return 0;
}
