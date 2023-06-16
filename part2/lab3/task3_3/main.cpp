/* 3.3 Використання шаблонів для зворотного виклику
 * В окремому заголовному файлі створити шаблонну функцію для розв'язання завдання 1.2
 * шостої лабораторної роботи попереднього семестру.
 * Першим параметром функції повинен бути об'єкт шаблонного типу, до якого можна застосувати операцію "круглі дужки".
 * Роботу шаблону перевірити на двох функціях, які підлягають дослідженню.
 * Одна з функцій повинна бути реалізована як функціональний об'єкт.
 * Примітка: Для обчислення першої (другої) похідної слід додати окремі шаблонні функції.
 *
 * Умова індивідуального завдання 1.2 лабораторної рооти № 6 (семестр 1):
 * Написати програму, яка реалізує перебір значень на визначеному інтервалі з певним кроком з метою пошуку
 * деякого значення відповідно до індивідуального завдання, наведеного в таблиці. Необхідне значення може бути
 * знайдено шляхом перевірки проміжних значень функції (або першої / другої похідної).
 * Слід використати вказівник на функцію, для якого визначити typedef.
 * Сирцевий код повинен бути розділений на дві одиниці трансляції.
 * Перша одиниця трансляції буде представлена заголовним файлом і файлом реалізації. Визначення typedef,
 * а також прототип функції пошуку потрібного значення, повинні бути розташовані в заголовному файлі.
 * Визначення цієї функції слід здійснити у файлі реалізації. Функція для перевірки працездатності програми,
 * а також функція main(), повинні бути розташовані в іншій одиниці трансляції.
 * Номер варіанту (номер студента у списку): 25.
 * Правило пошуку: Найменший корінь першої похідної.
 * Слід перевірити працездатність програми не менш ніж на двох довільних функціях.
 * Одна з функцій може бути стандартною.
 * Корінь – це точка, в якій функція повертає нуль.
 * Примітка: Для обчислення першої похідної y(x) можна використати таку формулу:
 * y'(x) = (y(x + Δx) - y(x)) / Δx, де Δx - деяке невеличке значення, наприклад 0.0000001. */

/* Commands to run:
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic main.cpp -o task3_3
./task3_3
*/

//Using templates
#include "header.h"

double powFunction(double x) {
    return pow(x, 2); //The derivative of pow of two function is 2x
}

//Class for creating a functional object
class powFunctionalObject {
public:
    //Overload the operation of a function call
    double operator()(double x) {
        return pow(x,2); //The derivative of pow of two function is 2x
    }
};

int main() {
    //Using a template function with the powFunction
    std::cout << "The pow of two function:\n";
    std::cout << "The square root of minimum value of the first derivative on the interval [1; 6] (step = 2): "
    << findSqrtMinDerivative(powFunction, 1, 6, 2) << "\n";

    //Using a template function with the functional object powFunction
    try {
        powFunctionalObject powFunction;
        std::cout << "The square root of minimum value of the first derivative on the interval [-3; 6] (step = 1): "
                  << findSqrtMinDerivative(powFunction, -3, 6, 1) << "\n";
    }
    catch (const char* string) {
        std::cout << string;
    }

    return 0;
}
