/* 3.5 Бібліотека шаблонних функцій для роботи з масивом (додаткове завдання)
 * Створити заголовний файл з функціями, які працюють з масивом довільного узагальненого типу.
 * Слід реалізувати такі функції:
 * - обмін місцями елементів зі вказаними індексами;
 * - пошук елемента з певним значенням;
 * - обмін місцями усіх пар сусідніх елементів (з парним і непарним індексом).
 * Здійснити демонстрацію роботи усіх функцій з використанням даних як мінімум трьох різних типів. */

/* Commands to run:
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic main.cpp -o task3_5
./task3_5
*/

//Array
#include "header.h"

using std::array;
using std::cout;

int main() {
    //Testing swapElements
    array<int, 4> array1 = { -10, 34, 9, 99};
    cout << "Initial array1:" << "\n";
    for (const auto& elem : array1) {
        cout << elem << " ";
    }
    cout << "\n";

    cout << "Swapped elements 1 and 3 in array1:" << "\n";
    swapElements(array1, 1, 3);
    for (const auto& elem : array1) {
        cout << elem << " ";
    }
    cout << "\n\n";

    //Testing findElement
    array<double, 4> array2 = { 12.8, -3.2, 5.2, 10.9 };
    cout << "Initial array2:" << "\n";
    for (const auto& elem : array2) {
        cout << elem << " ";
    }
    cout << "\n";
    cout << "Element with value 5.2 found at index: " << findElement(array2, 5.2) << "\n\n";

    //Testing swapNeighbours
    array<char, 11> array3 = { 'p', 'r', 'o', 'g', 'r', 'a', 'm', 'm', 'i', 'n', 'g'};
    cout << "Initial array3:" << "\n";
    for (const auto& elem : array3) {
        cout << elem << " ";
    }
    cout << "\n";

    cout << "Swapped neighbours in array3:" << "\n";
    swapNeighbours(array3);
    for (const auto& elem : array3) {
        cout << elem << " ";
    }
    cout << "\n";

    return 0;
}
