#include <iostream>
#include <cmath>

/*
 * Test:
 * 0 2 -4
 * x = 2
 *
 * 3 -14 -5
 * x1 = 5
 * x2 = -0.33333
 *
 * 1 2 2
 * No solution
 * */
int getNumberOfSolution(double a, double b, double c, double& x1, double& x2) {
    if (a == 0) {
        if (b != 0) {
            x1 = -(c/b);

            return 1;
        } else {
            return (c != 0) ? 0 : -1;
        }
    } else if (b == 0 && c != 0) {
        if (-c / a > 0) {
            x1 = sqrt(-c / a), x2 = -sqrt(-c / a);

            return 2;
        } else {
            return 0;
        }
    } else {
        double discriminant = (b * b) - (4 * a * c);
        if (discriminant > 0) {
            x1 = ((-b) + sqrt(discriminant)) / (2 * a);
            x2 = ((-b) - sqrt(discriminant)) / (2 * a);

            return 2;
        } else if (discriminant == 0) {
            x1 = -b/ (2 * a);

            return 1;
        } else {
            return 0;
        }
    }
}

int main() {
    double a, b, c, x1, x2;

    std::cout << "Please, enter double value of variables: a, b, c separated by space: ";
    std::cin >> a >> b >> c;

    int result = getNumberOfSolution(a, b, c, x1, x2);

    if (result == 0) {
        std::cout << "The roots do not exist or imaginary." << std::endl;
    } else if (result == -1) {
        std::cout << "There are an infinite number of solutions." << std::endl;
    } else if (result == 1) {
        std::cout << "Result: x=" << x1 << std::endl;
    } else if (result == 2) {
        std::cout << "Result: x1=" << x1 << "; " << "x2=" << x2 << std::endl;
    } else {
        std::cerr << "Error! Function `getNumberOfSolution()` return invalid result." << std::endl;
        return 1;
    }

    return 0;
}

