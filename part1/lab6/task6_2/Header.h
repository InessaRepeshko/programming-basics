#ifndef CPP_LABORATORY_6_2_HEADER_H
#define CPP_LABORATORY_6_2_HEADER_H

typedef double (*Callback) (double x);
double get_res_derivative(double x, Callback callbackFunction, double eps);
double find_min(double start, double end, double step, Callback callbackFunction);

#endif
