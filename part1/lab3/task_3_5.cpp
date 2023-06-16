#include <iostream>

double y(double x, int n) {
    double y;

    if (x > 0) {
        y = 1;
        for (int i = 1; i <= n - 1; i++) {
            double subLoopSum = 0;
            for (int j = 0; j <= i; j++) {
                subLoopSum += i / ((double)j + x);
            }

            y *= subLoopSum;
        }
    } else {
        y = 0;
        for (int i = 2; i <= n - 1; i++) {
            y += (double)x / i;
        }
    }

    return y;
}

bool readConsole(double& start, double& end, double& step, int& numberOfIterations) {
    std::cout << "Enter, value start and end of interval, step and number of iterations.";
    std::cin >> start >> end >> step >> numberOfIterations;

    if (start >= end) {
        std::cerr << "Runtime error! Start variable must be less end." << std::endl;
        return false;
    }

    if (step <= 0) {
        std::cerr << "Runtime error! Step must be greater than zero." << std::endl;
        return false;
    }

    if (numberOfIterations <= 0) {
        std::cerr << "Runtime error! Number of iterations must be greater than zero." << std::endl;
        return false;
    }

    return true;
}

void printInALoop(double start, double end, double step, int numberOfIterations)
{
    std::cout << "X\tY" << std::endl;
    std::cout << "------" << std::endl;
    for (double x = start; x <= end; x += step) {
        std::cout << x << "\t" << y(x, numberOfIterations) << std::endl;
    }
}

int main()
{
    double start, end, step;
    int numberOfIterations;
    if (readConsole(start, end, step, numberOfIterations)) {
        printInALoop(start, end, step, numberOfIterations);

        return 0;
    }

    return -1;
}
