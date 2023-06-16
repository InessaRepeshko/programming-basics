/* 1.3 Представлення й обробка даних про студентів
 Створити структуру для представлення даних про студента. Структура повинна містити такі елементи даних:
 - номер студентського посвідчення (unsigned int);
 - прізвище (рядок у вигляді масиву символів);
 - оцінки за останню сесію у вигляді масиву цілих від 0 до 100 (оцінки за предметами).

 Реалізувати функцію яка здійснює виведення даних про студента у консольне вікно.
 Першим параметром функції повинна бути структура, яка описує студента.
 Реалізувати функції, які отримують масив вказівників на студентів і довжину масиву і здійснюють:
 - сортування масиву за ознакою, яка наведена в індивідуальному завданні;
 - пошук даних про студентів, які відповідають умові, наведеній в індивідуальному завданні.
 - виведення всіх елементів масиву в консольне вікно.
 Під час сортування масиву структур замість обміну місцями двох структур
 здійснювати обмін місцями елементів масиву вказівників.

 Створити масив студентів. Створити масив вказівників на студентів,
 заповнивши його адресами структур з масиву студентів. Продемонструвати сортування й пошук студентів.

 Індивідуальне завдання:
 1. Номер студента у списку групи: 25.
 2. Умова сотрування: за зменшенням добутку оцінок.
 3. Умова вибору даних: з парною довжиною прізвища. */

/* Commands to run:
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task1_3.cpp -o task1_3
./task1_3
*/

#include <iostream>
#include <cstring>

// Визначення констатнтних значень кількості оцінок здобутих студентом за результатами останньої сесії
// та максимальної довжини прізвища студента.
const int numberOfGrades = 8;
const int lengthOfLastName = 50;

// Структура для опису даних студента: номер студентського, прізвище, оцінки за останню сессію.
struct Student {
    unsigned int ID;
    char lastName[lengthOfLastName];
    unsigned int grades[numberOfGrades];
};

// Функція для виводу у консоль даних одного студента.
void printStudent(const Student& student) {
    std::printf("\nID: %d\tLast Name: %s\tGrades:\t", student.ID, student.lastName);

    for (int i = 0; i < numberOfGrades; i++) {
        std::printf("%d\t", student.grades[i]);
    }
}

// Функція для виводу у консоль переданого списку студентів.
void printStudentList(Student** studentList, int numberOfStudents) {
    for (int i = 0; i < numberOfStudents; i++) {
        printStudent(*studentList[i]);
    }
}

// Функція для пошуку добутку оцінок кожного студента.
unsigned long long calculateGradeMultiplier(const Student& student) {
    unsigned long long gradesMultiplier = 1;

    for (int i = 0; i < numberOfGrades; i++) {
        gradesMultiplier *= student.grades[i];
    }

    return gradesMultiplier;
}

// Функція для сортування за зменшенням добутку оцінок студентів,
// що реалізована за допомогою бульбашкового сортування.
void sortByDescendingGradeMultiplier(Student** studentList, int numberOfStudents) {
    for (int i = 0; i < numberOfStudents; i++) {
        for (int j = i + 1; j < numberOfStudents; j++) {
            if (calculateGradeMultiplier(*studentList[i])
                < calculateGradeMultiplier(*studentList[j])) {
                    Student *temp = studentList[i];
                    studentList[i] = studentList[j];
                    studentList[j] = temp;
            }
        }
    }
}

// Функція для визначення довжини прізвища студента.
unsigned int calculateLengthOfLastName(const char* lastName) {
    return (unsigned int) std::strlen(lastName);
}

// Функція для вибору даних із масиву студентів за умовою,
// що довжина прізвища студента парна.
void selectByEvenLength(Student** studentList, int numberOfStudents) {
    for (int i = 0; i < numberOfStudents; i++) {
        if (calculateLengthOfLastName(studentList[i]->lastName) % 2 == 0) {
            printStudent(*studentList[i]);
        }
    }
    std::printf("\n");
}

int main() {
    // Створення і заповнення масиву даними студентів.
    const int numberOfStudents = 6;
    Student studentList[numberOfStudents] = {
            {22201,"Antropov",
                            {90,90,80,84, 90, 87, 90, 95}},
            {22202, "Prokopov",
                            {90,95,95,80, 94, 96, 90, 85}},
            {22203, "Chernenko",
                            {75,80,85,90, 85, 85, 90, 95}},
            {22204, "Krovskiy",
                            {80,78,75,76, 78, 80, 85, 90}},
            {22205, "Reshetnyak",
                            {100,95,96,97, 98, 99, 90, 90}},
            {22206,"Zvyagintsev",
                            {100,100,100,100, 100, 100, 100, 100}}
    };

    // Створення і заповнення масиву указівників.
    Student* studentPointer[numberOfStudents];

    for (int i = 0; i < numberOfStudents; i++) {
        studentPointer[i] = &studentList[i];
    }

    // Вивід на екран первинного списку студентів.
    std::printf("\nInitial student list:\n");
    printStudentList(studentPointer, numberOfStudents);

    // Сортування списку за зменшенням добутку оцінок та вивід результуючого списку у консоль.
    std::printf("\n\nStudent list is sorted by descending student grade multiplier:\n");
    sortByDescendingGradeMultiplier(studentPointer, numberOfStudents);
    printStudentList(studentPointer, numberOfStudents);

    // Вибір даних з масиву за парною довжиною прізвища студента та вивід їх у консоль.
    std::printf("\n\nStudent list is selected by even student last name:\n");
    selectByEvenLength(studentPointer, numberOfStudents);

    return 0;
}
