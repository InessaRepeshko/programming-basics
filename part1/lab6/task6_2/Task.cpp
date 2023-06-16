#include "cmath"
#include "Header.h"
#include "iostream"

double function_one(double x) {
    return pow(x, 2);
}

double function_two(double x) {
    return pow(x, 3) * 0.5;
}

int main() {
    double start, end, step;
    std::cout << "Type `start`, `end`, `step`: ";
    std::cin >> start >> end >> step;

    double result_one = find_min(start, end, step, function_one);

    if (isnan(result_one)) {
        std::cout << "First function dont have root." << std::endl;
    } else {
        std::cout << "First function max root: " << result_one << std::endl;
    }

    double result_two = find_min(start, end, step, function_two);

    if (isnan(result_two)) {
        std::cout << "Second function dont have root." << std::endl;
    } else {
        std::cout << "Second function max root: " << result_two << std::endl;
    }

    return 0;
}
