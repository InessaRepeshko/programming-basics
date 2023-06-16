#include "Header.h"
#include "math.h"

double get_res_derivative(double x, Callback callbackFunction, double eps = 0.0000001) {
    return (callbackFunction(x + eps) - callbackFunction(x))/ eps;
}

double find_min(double start, double end, double step, Callback callbackFunction) {
    double min_root = NAN;
    double x = start;

    while (x < end) {
        double y = get_res_derivative(x, callbackFunction);

        if (y < 0.0001 && (x < min_root || isnan(min_root))) {
            min_root = x;
        }

        x += step;
    }

    return min_root;
}
