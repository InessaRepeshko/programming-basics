#include "iostream"
#include "cmath"
#include "ctime"

const int NUMBER_OF_COLUMNS = 4;
const int NUMBER_OF_ROWS = 5;

int maxValueOfArray(int arr[], int n) {
    double max = arr[0];
    for(int i = 1; i < n; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }

    return max;
}

void task1(int arr[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], int modifiedArr[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS]) {
    for (int i = 0; i < NUMBER_OF_ROWS; ++i) {
        for (int j = 0; j < NUMBER_OF_COLUMNS; j++) {
            if (arr[i][j] % 2  == 0 && arr[i][j] > 0) {
                modifiedArr[i][j] = arr[i][j] * 2;
            } else {
                modifiedArr[i][j] = arr[i][j];
            }

        }
    }
}

void task2(int arr[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], double newArr[NUMBER_OF_COLUMNS]) {
    for (int t = 0; t < NUMBER_OF_COLUMNS; ++t) {
        int arrayWithColumnValues[NUMBER_OF_ROWS];
        for (int i = 0; i < NUMBER_OF_ROWS; ++i) {
            arrayWithColumnValues[i] = arr[i][t];
        }

        newArr[t] = cbrt(maxValueOfArray(arrayWithColumnValues, NUMBER_OF_ROWS));
    }
}

void generateRandomNumberInArray(int arr[][NUMBER_OF_COLUMNS]) {
    srand(time(0));

    for (int i = 0; i < NUMBER_OF_ROWS; ++i) {
        for (int j = 0; j < NUMBER_OF_COLUMNS; ++j) {
            arr[i][j] = rand() % 20;
        }
    }
}

void printResult(int arr[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS]) {
    std::cout << "{" << std::endl;

    for (int i = 0; i < NUMBER_OF_ROWS; ++i) {
        std::cout << " {";
        for (int j = 0; j < NUMBER_OF_COLUMNS; ++j) {
            std::cout << " " << arr[i][j] << " ";
        }
        std::cout << "}" << std::endl;
    }
    std::cout << "}" << std::endl;
}

int main() {
    int arr[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
    int modifiedArr [NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
    double newArr[NUMBER_OF_COLUMNS];

    generateRandomNumberInArray(arr);
    task1(arr, modifiedArr);
    task2(arr, newArr);

    std::cout << "Array before: ";
    printResult(arr);

    std::cout << "Array after modification: ";
    printResult(modifiedArr);

    std::cout << "New array: ";
    std::cout << "{";
    for (int j = 0; j < NUMBER_OF_COLUMNS; ++j) {
        std::cout << " " << newArr[j] << " ";
    }
    std::cout << "}";
}

