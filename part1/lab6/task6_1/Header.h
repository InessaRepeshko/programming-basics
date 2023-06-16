#ifndef CPP_LABORATORY_6_HEADER_H
#define CPP_LABORATORY_6_HEADER_H

typedef double(*Callback) (double, int);
void runCalculating(
        double start,
        double end,
        double step,
        int numberOfIterations,
        Callback function
        );

#endif
