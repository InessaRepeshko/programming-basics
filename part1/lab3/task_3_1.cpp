#include <iostream>

void validateValue(int number) {
    static int minNumber = INT_MAX, maxNumber = INT_MIN;

    if (number < minNumber) {
        minNumber = number;
    }

    if (number > maxNumber) {
        maxNumber = number;
    }

    std::cout << "Maximum entered number: " << maxNumber << std::endl;
    std::cout << "Minimum entered number: " << minNumber << std::endl;
}

int main() {
    int number;

    do {
        std::cout << "Please, enter number: ";
        std::cin >> number;
        validateValue(number);
    } while (number >= INT_MIN || number <= INT_MAX);

    return 0;
}
