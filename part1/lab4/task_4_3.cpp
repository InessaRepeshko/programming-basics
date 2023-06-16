#include "iostream"

double max(double arr[], int n) {
    double max = arr[0];
    for(int i = 1; i < n; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }

    return max;
}

double min(double arr[], int n) {
    double min = arr[0];
    for(int i = 1; i < n; i++) {
        if(min > arr[i]) {
            min = arr[i];
        }
    }

    return min;
}

int main() {
    int n = 7;
    double arr[] = {1, 2, 3, 4, 5, 6, 7};

    std::cout << "Result of sum max and min number is " << min(arr, n) + max(arr, n);
    return 0;
}