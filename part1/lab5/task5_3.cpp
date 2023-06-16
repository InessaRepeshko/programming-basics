#include "iostream"
#include "filesystem"
#include "cmath"
#include "fstream"
#include "iomanip"

int NUMBER_OF_COLUMNS = 4;
int NUMBER_OF_ROWS = 5;

int maxValueOfArray(int arr[], int n) {
    double max = arr[0];
    for(int i = 1; i < n; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }

    return max;
}

int main() {
    std::ifstream fileIn;
    fileIn.open("array.txt");
    if (!fileIn.is_open()) {
        printf("Error! Not file.");
        return -1;
    }

    fileIn >> NUMBER_OF_ROWS >> NUMBER_OF_COLUMNS;

    int** arr = new int* [NUMBER_OF_ROWS];

    for (int i = 0; i < NUMBER_OF_ROWS; ++i) {
        arr[i] = new int [NUMBER_OF_COLUMNS];
        for (int j = 0; j < NUMBER_OF_COLUMNS; ++j) {
            fileIn >> arr[i][j];
        }
    }

    printf("Read array\n{\n");
    for (int i = 0; i < NUMBER_OF_ROWS; ++i) {
        printf("{");
        for (int j = 0; j < NUMBER_OF_COLUMNS; ++j) {
            printf(" %i ", arr[i][j]);
        }
        printf("} \n");
    }
    printf("}\n");

    fileIn.close();

    std::ofstream fileModified("modifiedArray.txt");
    for (int i = 0; i < NUMBER_OF_ROWS; ++i) {
        for (int j = 0; j < NUMBER_OF_COLUMNS; j++) {
            if (arr[i][j] % 2  == 0 && arr[i][j] > 0) {
                arr[i][j] = arr[i][j] * 2;
            } else {
                arr[i][j] = arr[i][j];
            }
        }
    }

    printf("Modified array\n{\n ");
    for (int i = 0; i < NUMBER_OF_ROWS; ++i) {
        printf("{");
        for (int j = 0; j < NUMBER_OF_COLUMNS; ++j) {
            printf(" %i ", arr[i][j]);
            fileModified << arr[i][j] << " ";
        }
        printf("} \n");
    }
    printf("}\n");
    fileModified.close();

    std::ofstream fileNewArr("newArray.txt");

    double* newArr = new double[NUMBER_OF_COLUMNS];
    for (int t = 0; t < NUMBER_OF_COLUMNS; ++t) {
        int arrayWithColumnValues[NUMBER_OF_ROWS];
        for (int i = 0; i < NUMBER_OF_ROWS; ++i) {
            arrayWithColumnValues[i] = arr[i][t];
        }

        newArr[t] = cbrt(maxValueOfArray(arrayWithColumnValues, NUMBER_OF_ROWS));
    }

    printf("New array\n{\n ");
    for (int j = 0; j < NUMBER_OF_COLUMNS; ++j) {
        printf(" %g ", newArr[j]);
        fileNewArr << newArr[j] << " ";
    }
    printf("}\n");

    fileNewArr.close();

    delete[] newArr;

    for (int i = 0; i < NUMBER_OF_ROWS; ++i) {
        delete[] arr[i];
    }

    delete[] arr;
}
