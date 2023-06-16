#include <iostream>

int main() {
    double x;
    int n, k;

    std::cout << "Hello! Task 1.2! Enter integer value for variables: x, k, n: ";

    std::cin >> x >> k >> n;

    if (k > n) {
        std::cerr << "Runtime Error! Variable K must be greater than variable N." << std::endl;
        return 1;
    }

    double y = 0;
    for (int i = 1; i <= n; i++) {
        if (i == k) continue;

        y += i/(x + 2 * i);
    }

    printf("Result: y = %g \n", y);
    return 0;
}
