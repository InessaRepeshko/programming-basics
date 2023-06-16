#include <iostream>

int main() {
    double eps;

    std::cout << "Enter float value of 'eps': ";
    std::cin >> eps;

    std::cout << eps << std::endl;

    if (eps <= 0 || eps >= 1) {
        std::cerr << "Runtime Error! Value of epsilon must be greater than 0 and less than 1.\n";
        return 1;
    }

    int divider = 2;
    double sum, y = 0, divisibleNumber = 1;
    do {
        sum = divisibleNumber / divider;
        if (sum < eps) {
            break;
        }

        divider *= 2;
        y += sum;
    }
    while (true);

    printf("Result: y = %g;", y);
    return 0;
}
