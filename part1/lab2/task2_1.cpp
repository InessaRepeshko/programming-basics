#include <iostream>
#include <cmath>

int main() {
    double a, b, c;

    std::cout << "Hello! Task 1.1. Enter number value of variables a, b, c: ";
    std::cin >> a >> b >> c;

    if (a == 0) {
        if (b != 0) {
            double x = -(c/b);
            printf("Result: x = %g\n", x);
        } else {
            if (c != 0) {
                printf("The roots do not exist or imaginary.\n");
            } else {
                printf("There are an infinite number of solutions.\n");
            }
        }
    } else if (a != 0 && b == 0 && c != 0) {
        if (-c / a > 0) {
            double
                x1 = sqrt(-c / a),
                x2 = -sqrt(-c / a);

            printf("Result: x1 = %g; x2 = %g\n", x1, x2);
        } else {
            printf("The roots do not exist or imaginary.\n");
        }
    } else {
        double discriminant = (b * b) - (4 * a * c);
        if (discriminant > 0) {
            double x1 = ((-b) + sqrt(discriminant)) / (2 * a);
            double x2 = ((-b) - sqrt(discriminant)) / (2 * a);

            printf("Result: x1 = %g; x2 = %g\n", x1, x2);
        } else if (discriminant == 0) {
            double x = -b/ (2 * a);
            printf("Result: x = %g\n", x);
        } else {
            printf("The roots do not exist or imaginary.\n");
        }
    }

    return 0;
}
