#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cmath>

//Template function that calculates the value of the first derivative
template<typename F> double findDerivative(F function,double x, double eps = 0.00000001) {
    return (function(x + eps) - function(x)) / eps;
}

//Template function that calculates the square root of minimum value from those values
//that were on the specified interval with a certain step
template<typename F> double findSqrtMinDerivative(F function, double start, double end, double step) {
    double min = findDerivative(function, start);

    for (double x = start + step; x <= end; x += step) {
        if (min > findDerivative(function, x)) {
            min = findDerivative(function, x);
        }
    }

    if (min < 0) {
        throw "the square root of the minimum value of the first derivative which is a negative number cannot be found.\n";
    }

    return sqrt(min);
}

#endif
