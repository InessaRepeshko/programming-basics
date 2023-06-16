#include <iostream>
#include "Header.h"

double calculateLogicOne(double x, int n) {
    double y = 0;

    if (x > 0) {
        y = 1;

        for (int i = 1; i <= n - 1; i++) {
            double subLoopSum = 0;

            for (int j = 0; j <= i; j++) {
                subLoopSum += i / ((double) j + x);
            }

            y *= subLoopSum;
        }
    }

    return y;
}

double calculateLogicTwo(double x, int n) {
    double y = 0;

    if (x <= 0) {
        for (int i = 2; i <= n - 1; i++) {
            y += (double) x / i;
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

    if (step < 0) {
        std::cerr << "Runtime error! Step must be greater than zero." << std::endl;
        return false;
    }

    if (numberOfIterations <= 0) {
        std::cerr << "Runtime error! Number of iterations must be greater than zero." << std::endl;
        return false;
    }

    return true;
}

int main() {
    double start, end, step;
    int numberOfIterations;

    if (readConsole(start, end, step, numberOfIterations)) {
        printf("Result calculateLogicOne()`\n");
        runCalculating(start, end, step, numberOfIterations, calculateLogicOne);

        printf("Result calculate Logic Two ()`\n");
        runCalculating(start, end, step, numberOfIterations, calculateLogicTwo);

        return 0;
    }

    return -1;
}
