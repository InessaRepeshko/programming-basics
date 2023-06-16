#include <iostream>

int main() {
    int a, b, h, n;

    std::cout << "Hello! Please, enter integer values for variables a, b, h, n separated by space: ";
    std::cin >> a >> b >> h >> n;

    if (a > b) {
        std::cerr << "Critical error! Variable 'a' must be less than 'b'." << std::endl;
        return 1;
    }

    if (h <= 0) {
        std::cerr << "Critical error! Variable 'h' must be greater than 0." << std::endl;
        return 1;
    }

    int x = a;
    while (x <= b) {

        if (x > 0) {
            double y = 1;
            for (int i = 1; i <= n - 1; i++) {
                double subLoopSum = 0;
                for (int j = 0; j <= i; j++) {
                    subLoopSum += i / ((double)j + x);
                }

                y *= subLoopSum;
            }

            printf("Result (x > 0): x=%d; y=%g\n", x, y);
        } else {
            double y = 0;
            for (int i = 2; i <= n - 1; i++) {
                y += (double)x / i;
            }

            printf("Result (x <= 0): x=%d; y=%g\n", x, y);
        }

        x += h;
    }

    return 0;
}
