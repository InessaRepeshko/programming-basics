#include <iostream>
#include "Header.h"

void runCalculating(double start, double end, double step, int numberOfIterations, Callback function) {
    std::cout << "X\tY" << std::endl;
    std::cout << "------" << std::endl;

    for (double x = start; x <= end; x += step) {
        std::cout << x << "\t" << function(x, numberOfIterations) << std::endl;
    }
}
