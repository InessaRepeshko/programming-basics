#include "iostream"
#include "ctime"
#include "cstdio"

using namespace std;

double maxValue(double* arr, int n) {
    double max = *arr;
    for(int i = 1; i < n; i++) {
        if(max < *arr + 1) {
            max = *arr + 1;
        }
    }

    return max;
}

double minValue(double* arr, int n) {
    double min = *arr;
    for(int i = 1; i < n; i++) {
        if(min > *arr + 1) {
            min = *arr + 1;
        }
    }

    return min;
}


int main() {
    int n;

    printf("Enter `n` - array size: ");
    scanf("%d", &n);

    if (n <= 0) {
        cerr << "Runtime error! `n` <= 0";
        return -1;
    }

    double* arr = new double[n];

    srand(time(0));
    printf("Array:");
    for (int i = 0; i < n; ++i) {
        arr[i] = (rand() / (RAND_MAX + 0.1)) * 20;
        printf(" %f", arr[i]);
    }

    double min = minValue(arr, n);
    double max = maxValue(arr, n);
    double sumMinMax = min + max;

    printf("\nMin value: %f\nMax value: %f\nSum min and max values: %f", min, max, sumMinMax);

    delete[] arr;
    return 0;
}

