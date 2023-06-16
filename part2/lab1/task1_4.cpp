/* 1.4 Робота зі зв'язаним списком
 Написати програму, яка забезпечує файлове введення та виведення і включає
 індивідуальне завдання лабораторної роботи № 4 курсу "Основи програмування (частина 1)".
 Слід реалізувати такі дії:
 - визначення константи (n) яка визначає кількість стовпців двовимірного масиву;
 - відкриття файлу для читання (файл повинен бути підготовлений за допомогою текстового редактора);
 - читання цілих чисел до кінця файлу і зберігання їх у зв'язаному списку;
 - створення двовимірного масиву в динамічній пам'яті; кількість рядків повинна бути обчислена
 на основі кількості зчитаних з файлу значень та визначеної кількості стовпців;
 - заповнення двовимірного масиву рядок за рядком; відсутні елементи останнього рядка повинні бути заповнені нулями;
 - видалення елементів зв'язаного списку з динамічної пам'яті;
 - реалізація індивідуального завдання лабораторної роботи № 4 курсу "Основи програмування (частина 1)";
 - зберігання результатів в новому файлі;
 - видалення масивів операцією delete. */

/* Умова індивідуального завдання з лабораторної роботи № 4 курсу "Основи програмування (частина 1)":
 Створити програму, яка визначає та ініціалізує двовимірний масив цілих елементів, а потім реалізує такі дії:
 - перетворення вихідного масиву відповідно до завдання, наведеного в колонці "Перший крок";
 - створення та заповнення одновимірного масиву чисел типу double відповідно до завдання,
 наведеного в колонці "Другий крок";
 - виведення на екран елементів обох масивів.
 Треба передбачити виведення повідомлень про помилки, якщо перетворення або заповнення неможливі.

 Індивідуальне завдання:
 1. Номер студента у списку групи: 25.
 2. Перший крок. Правило перетворення елементів першого масиву:
    Всі додатні елементи з парними значеннями повинні бути збільшені в два рази.
 3. Другий крок. Правило заповнення елементів другого масиву:
    Кубічні корені максимальних елементів колонок.
 4. Кількість рядків m: 5.
 5. Кількість стовпців n: 4. */

/* Commands to run:
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task1_4.cpp -o task1_4
./task1_4 input.txt
*/

#include <iostream>
#include <fstream>
#include <cmath>

// Визначення константи (n), яка визначає кількість стовпців двовимірного масиву.
const int n = 4;

// Визначення назв вхідного файлу з даними та вихідного файлу для запису результатів.
const char* inputFileName = "input.txt";
const char* outputFileName = "output.txt";

// Опис структури звʼязного списку.
struct Node {
    int data;
    Node* next;
};

// Створення файлу для збереження результатів.
std::ofstream createOutputFile(const char* outputFileName) {
    // Створення файлу.
    std::ofstream outputFile(outputFileName);

    // Виведення повідомлення про помилку, якщо відкриття файлу неможливе.
    if (!outputFile.is_open()) {
        std::cerr << "Input file could not be opened." << std::endl;

        exit(1);
    }

    return outputFile;
}

// Відкриття файлу для читання та запис чисел з файлу у звʼязний список.
int readDataFromFile(const char* inputFileName, Node*& head) {
    // Відкриття файлу для читання (файл повинен бути підготовлений за допомогою текстового редактора).
    std::ifstream inputFile(inputFileName);

    // Виведення повідомленя про помилку, якщо заповнення масиву неможливе.
    if (!inputFile.is_open()) {
        std::cerr << "Input file could not be opened." << std::endl;

        exit(1);
    }

    // Читання цілих чисел до кінця файлу і зберігання їх у зв'язаному списку.
    int counter = 0; // Лічильник для підрахунку кількості елементів.
    int value;

    while (inputFile >> value) {
        counter++;
        Node* current = new Node;
        current->data = value;
        current->next = head;
        head = current;
    }

    inputFile.close();

    return counter;
}

// Обчислення кількості рядків на основі кількості зчитаних з файлу значень та визначеної кількості стовпців (n).
int calculateNumberOfRows(int counter, const int n) {
    int m;

    if (counter % n == 0) {
        m = counter / n;
    } else {
        m = counter / n + 1; // m = ceil(static_cast<double>(counter) / n);
    }

    return m;
}

// Cтворення двовимірного масиву в динамічній пам'яті.
int** createArray(const int n, int m) {
    int **array = new int *[m];

    for (int i = 0; i < m; i++) {
        array[i] = new int[n];
    }

    return array;
}

// Заповнення двовимірного масиву рядок за рядком.
// Відсутні елементи останнього рядка повинні бути заповнені нулями.
void fillArray(int** array, const int n, int m, Node*& head) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (head != nullptr) {
                array[i][j] = head->data;
                head = head->next;
            } else {
                array[i][j] = 0;
            }
        }
    }
}

// Видалення елементів зв'язаного списку з динамічної пам'яті.
void deleteLinkedList(Node* head) {
    Node* temp = head;

    while (head != nullptr) {
        head = temp;

        if (temp) {
            temp = temp->next;
        }

        delete head;
    }
}

// Виведення повідомленя про помилку, якщо перетворення початкового масиву даних неможливе.
void checkAbilityToTransform(int** array, const int n, int m) {
    bool abilityToTransform = false;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (array[i][j] % 2 == 0
                && array[i][j] > 0) {
                abilityToTransform = true;
            }
        }
    }

    if (!abilityToTransform) {
        std::cerr << "There are no positive even numbers in the array, so conversion is impossible." << std::endl;

        exit(1);
    }
}

// Перетворення вихідного масиву відповідно до завдання, наведеного в колонці "Перший крок".
// Перший крок. Правило перетворення елементів першого масиву:
// Всі додатні елементи з парними значеннями повинні бути збільшені в два рази.
int** doublingOfPositiveEvenElements(int** array, const int n, int m) {
    int **modifiedArray = createArray(n, m);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (array[i][j] % 2  == 0
                && array[i][j] > 0) {
                modifiedArray[i][j] = array[i][j] * 2;
            } else {
                modifiedArray[i][j] = array[i][j];
            }
        }
    }

    return modifiedArray;
}

// Пошук максимальних елементів колонок масиву даних.
int findMaxElementOfColumn(int* array, int m) {
    int max = array[0];

    for (int i = 1; i < m; i++) {
        if (max < array[i]) {
            max = array[i];
        }
    }

    return max;
}

// Cтворення та заповнення одновимірного масиву чисел типу double відповідно до завдання,
// наведеного в колонці "Другий крок".
// Другий крок. Правило заповнення елементів другого масиву:
// Кубічні корені максимальних елементів колонок.
double* calculateCubicRootsOfMaxElementsOfColumns(int** array, const int n, int m) {
    double* newArray = new double[n];

    for (int t = 0; t < n; ++t) {
        int* arrayWithColumnValues = new int[m];

        for (int i = 0; i < m; ++i) {
            arrayWithColumnValues[i] = array[i][t];
        }

        newArray[t] = cbrt(findMaxElementOfColumn(arrayWithColumnValues, m));
    }

    return newArray;
}

// Виведення у консоль елементів початкового та зміненого масиву даних.
void printArray(int** array, const int n, int m) {
    for (int i = 0; i < m; i++) {
        std::cout << "\t{\t";

        for (int j = 0; j < n; j++) {
            std::cout << array[i][j] << "\t";
        }

        std::cout << "}" <<std::endl;
    }
}

// Виведення у консоль елементів нового масиву даних.
void printArray(double* array, const int n) {
    std::cout << "\t{\t";

    for (int i = 0; i < n; i++) {
        std::cout << array[i] << "\t";
    }

    std::cout << "}";
}

// Зберігання в новому файлі даних початкового й зміненого масиву
// та виведення у консоль повідомлення про збереження даних.
void writeDataToFile(int** array, const int n, int m, std::ofstream& outputFile) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            outputFile << array[i][j] << "\t";
        }

        outputFile << std::endl;
    }
}

// Зберігання в новому файлі даних нового масиву та виведення у консоль повідомлення про збереження даних.
void writeDataToFile(double* array, int n, std::ofstream& outputFile) {
    for (int i = 0; i < n; i++) {
        outputFile << array[i] << "\t";
    }

    std::cout << std::endl;
}

// Видалення операцією delete початкового та зміненого массиву даних.
void deleteArray(int** array, int m) {
    for (int i = 0; i < m; i++) {
        delete[] array[i];
    }

    delete[] array;
}

// Видалення операцією delete нового масиву даних.
void deleteArray(double* newArray) {
    delete[] newArray;
}

int main() {
    // Створення вихідного файлу для запису результатів.
    std::ofstream outputFile = createOutputFile(outputFileName);

    // Створення елементу звʼязного списку.
    Node* head = nullptr;

    // Відкриття вхідного файлу для читання та запис чисел з файлу у звʼязний список.
    int counter = readDataFromFile(inputFileName, head);

    // Обчислення кількості рядків.
    int m = calculateNumberOfRows(counter, n);

    // Cтворення двовимірного масиву в динамічній пам'яті.
    int** array = createArray(n, m);

    // Заповнення двовимірного масиву.
    fillArray(array, n, m, head);

    // Видалення елементів зв'язаного списку з динамічної пам'яті.
    deleteLinkedList(head);

    // Виведення у консоль даних початкового масиву даних.
    std::cout << "Initial array:" << std::endl;
    printArray(array, n, m);

    // Зберігання в новому файлі даних початкового масиву та виведення повідомлення про збереження даних.
    outputFile << "Initial array:" << std::endl;
    writeDataToFile(array, n, m, outputFile);
    std::cout << "NOTICE! Initial array was written to the output file." << std::endl;

    // Виведення повідомленя про помилку, якщо перетворення початкового масиву даних неможливе.
    checkAbilityToTransform(array, n, m);

    // Перетворення початкового масиву даних у змінений масив даних та виведення у консоль даних зміненого масиву.
    array = doublingOfPositiveEvenElements(array, n, m);
    std::cout << "\nTransformed array with the doubled positive even elements of array:" << std::endl;
    printArray(array, n, m);

    // Зберігання в новому файлі даних зміненого масиву та виведення повідомлення про збереження даних.
    outputFile << "Transformed array:" << std::endl;
    writeDataToFile(array, n, m, outputFile);
    std::cout << "NOTICE! Transformed array was written to the output file." << std::endl;

    // Cтворення  і заповнення одновимірного масиву чисел та виведення у консоль даних нового масиву.
    double* newArray = new double[n];
    newArray = calculateCubicRootsOfMaxElementsOfColumns(array, n, m);
    std::cout << "\nNew array with cubic roots of max elements of columns:" << std::endl;
    printArray(newArray, n);

    // Зберігання в новому файлі даних нового масиву та виведення повідомлення про збереження даних.
    outputFile << "New array:" << std::endl;
    writeDataToFile(newArray, n, outputFile);
    std::cout << "NOTICE! New array was written to the output file." << std::endl;

    // Видалення з динамічної пам'яті початкового, зміненого та нового масивів даних.
    deleteArray(array, m);
    deleteArray(newArray);

    // Завершення роботи з новим файлом для запису результатів.
    outputFile.close();

    return 0;
}
