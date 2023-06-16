/* 2.1 Клас для представлення точки в тривімірному просторі
 * Створити клас для опису точки в тривимірному просторі. Клас повинен відповідати таким вимогам:
 * - мати конструктор без параметрів;
 * - мати конструктор с трьома параметрами;
 * - містити елементи даних типу double для представлення координат точки;
 * - реалізовувати публічні функції доступу до даних (сеттери й геттери).
 * Для обчислення відстані створити операторну функцію operator-() ("мінус") з двома параметрами типу класу
 * для представлення точок і результатом типу double. Функцію оголосити як друга класу.
 * У функції main() слід створити два об'єкти типу точки в тривімірному просторі,
 * застосувавши різні конструктори. Для встановлення і читання значень застосувати функції доступу.
 * Обчислити відстань між двома точками через використання операції "мінус",
 * потім змінити координати однієї з точок і обчислити відстань між двома точками
 * через явний виклик функції operator-(). */

/* Commands to run:
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_1.cpp -o task2_1
./task2_1
*/

//Point in 3D space
#include <iostream>
#include <cmath>

class Point3D {
    friend double operator-(const Point3D& point1, const Point3D& point2);
private:
    double x, y, z;
public:
    //The constructor without parameters
    Point3D() : x(0), y(0), z(0) {}
    //The constructor with 3 parameters
    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}
    //Methods for getting and setting coordinate values
    void setValueX(double x) { this->x = x; }
    double getValueX() const { return x; }
    void setValueY(double y) { this->y = y; }
    double getValueY() const { return y; }
    void setValueZ(double z) { this->z = z; }
    double getValueZ() const { return z; }
};

//Overloading the operator '-' for calculating the distance between two points
double operator-(const Point3D& point1, const Point3D& point2) {
    return std::sqrt(pow((point2.x - point1.x), 2)
                    + pow((point2.y - point1.y), 2)
                    + pow((point2.z - point1.z), 2));
}

int main() {
    //Creating two points:
    //point1 with default coordinates using the constructor without parameters,
    //point2 with specified coordinates using constructor with 3 parameters
    Point3D point1;
    Point3D point2(4.5, 5.5, 6.5);

    point1.setValueX(2.0);
    point1.setValueY(3.0);
    point1.setValueZ(5.0);
    printf("Point1 has coordinates (%.1lf; %.1lf; %.1lf).\n",
           point1.getValueX(), point1.getValueY(), point1.getValueZ());
    printf("Point2 has coordinates (%.1lf; %.1lf; %.1lf).\n",
           point2.getValueX(), point2.getValueY(), point2.getValueZ());

    //Calculating the distance between point1 and point2 using the overloaded operator '-'
    double distance = point2 - point1;
    printf("Distance between two points = %.4lf.\n", distance);

    printf("Changed cooridanates of the point1:\n");
    point1.setValueX(7.5);
    point1.setValueY(8.5);
    point1.setValueZ(9.5);
    printf("Point1 has coordinates (%.1lf; %.1lf; %.1lf).\n",
           point1.getValueX(), point1.getValueY(), point1.getValueZ());

    //Calculating the distance between two points by explicitly calling the operator-() function
    distance = operator-(point1, point2);
    printf("Distance between two points = %.4f.\n", distance);

    return 0;
}
