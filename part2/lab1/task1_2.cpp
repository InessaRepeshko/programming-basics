/* 1.2 Точки в тривимірному просторі
 Створити структуру для опису точки в тривимірному просторі (тип точки).
 Написати програму, яка обчислює відстань між двома точками.
 Для обчислення відстані створити функцію з двома параметрами типу структури для представлення точок. */

/* Commands to run:
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task1_2.cpp -o task1_2
./task1_2
*/

#include <iostream>
#include <cmath>

// Структура для опису точки у тривимірному просторі.
struct Point {
    double x, y, z;
};

// Обчислення вектору відстані між двома точками.
double vector(Point A, Point B) {
    return std::sqrt(
            pow((B.x - A.x), 2) +
            pow((B.y - A.y), 2) +
            pow((B.z - A.z), 2)
            );
}

int main() {
    Point A = {1, 2, 3};
    Point B = {4, 5, 6};
    std::printf("The distance between point A and point B is vector AB = %f.\n", vector(A, B));

    return 0;
}
