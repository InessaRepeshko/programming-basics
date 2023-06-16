/* Додаткове завдання №2: Використання лямбда-виразів для зворотного виклику
 * Розв'язати завдання 1.3 лабораторної роботи №3.
 * Замість функціональних об'єктів використовувати лямбда-вирази.
 * Функцію, яка обчислює необхідний результат відповідно до індивідуального завдання, розташувати в окремому модулі.
 * Замість підключення заголовних файлів використовувати імпорт з модулів. */

import std;
import SqrtMinDerivative;

#include <math.h>

int main() {
    std::cout << "Calculations for the pow of two function:\n";
    std::cout << "The square root of minimum value of the first derivative on the interval [3; 9] (step = 2): "
              << findSqrtMinDerivative([](double x) { return pow(x, 2); }, 3, 9, 2) << "\n\n";
    
    std::cout << "Calculations for the square root function:\n";
    std::cout << "The square root of minimum value of the first derivative on the interval [10; 20] (step = 5): "
              << findSqrtMinDerivative(sqrt, 10, 20, 5) << "\n\n";

    return 0;
}
