#include <iostream>

double overload(double arg = 1) {
    return arg;
}

double overload(double arg1, double arg2) {
    return arg1 * arg2;
}

int main() {
    std::cout << "Without arguments. Result: " << overload() << std::endl;
    std::cout << "With 1 argument. Result: " << overload(2.4) << std::endl;
    std::cout << "With 2 argument. Result: " << overload(2.4, 4) << std::endl;
}

