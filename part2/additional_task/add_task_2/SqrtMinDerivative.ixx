export module SqrtMinDerivative;

#include <math.h>

//Template function that calculates the value of the first derivative
template<typename F> double findDerivative(F function, double x, double eps = 0.00000001) {
	return (function(x + eps) - function(x)) / eps;
}

//Template function that calculates the square root of minimum value from values
//that were on the specified interval with a certain step
export template<typename F> double findSqrtMinDerivative(F function, double start, double end, double step) {
	double min = findDerivative(function, start);

	for (double x = start + step; x <= end; x += step) {
		if (min > findDerivative(function, x)) {
			min = findDerivative(function, x);
		}
	}

	return sqrt(min);
}
