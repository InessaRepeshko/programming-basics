#include "header.h"

//Function that calculates the value of the first derivative
double AbstractDerivative::findDerivative(double x, double eps) {
    return (someFunction(x + eps) - someFunction(x)) / eps;
}

//Function that calculates the square root of minimum value from those values
//that were on the specified interval with a certain step
double AbstractDerivative::findSqrtMinDerivative(double start, double end, double step) {
    double min = findDerivative(start);

    for (double x = start + step; x <= end; x += step) {
        if (min > findDerivative(x)) {
            min = findDerivative(x);
        }
    }

    if (min < 0) {
        throw "the square root of the minimum value of the first derivative which is a negative number cannot be found.\n";
    }

    return sqrt(min);
}
