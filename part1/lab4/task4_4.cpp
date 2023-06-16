#include "iostream"

void printResult(int arr[], int length) {
    for (int i = 0; i < length; ++i) {
        std::cout << "  " << arr[i];
    }
    std::cout << std::endl;
}

void sortArray(int arr[], int length) {
    for (int step = 0; step < length; ++step) {
        for (int i = 0; i < length - step; ++i) {
            if (arr[i] > arr[i + 1]) {
                int value = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = value;
            }
        }
    }
}

int main() {
    int arr[6] = {-45, 12, 0, 1, 5, 8};
    int length = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array before: ";
    printResult(arr, length);

    sortArray(arr, length);

    std::cout << "Array after function `sortArray()`: ";
    printResult(arr, length);

    return 0;
}

