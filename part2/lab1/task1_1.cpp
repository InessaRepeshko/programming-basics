/* 1.1 Перелік для представлення місяців року
 Створити перелік для представлення місяців року.
 Реалізувати та продемонструвати перевантаження операцій ++ і -- так,
 щоб після грудня йшов січень, а перед січнем – грудень. */

/* Commands to run:
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task1_1.cpp -o task1_1
./task1_1
*/

#include <iostream>

// Для можливості масштабування в майбутньому створимо окремий масив із назвами місяців на англійській мові
const char* MonthTitleEng[] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
};

// Іменований перелік місяців року
enum MonthOfYear {
    Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

// Перевантаження префіксної операції ++
MonthOfYear operator++(MonthOfYear& month) {
    month = (month == MonthOfYear::Dec) ? MonthOfYear::Jan : (MonthOfYear) (month + 1);
    //умова true - окремий випадок, false - всі інші місяці

    return month;
}

// Перевантаження постфіксної операції ++
MonthOfYear operator++(MonthOfYear& month, int) {
    MonthOfYear oldMonth = month; //зберігаємо попередній місяць
    operator++(month); //викликаємо попередню функцію

    return oldMonth; //повертаємо попередній місяць
}

// Перевантаження префіксної операції --
MonthOfYear operator--(MonthOfYear& month) {
    month = (month == MonthOfYear::Jan) ? MonthOfYear::Dec : (MonthOfYear) (month - 1);
    //умова true - окремий випадок, false - всі інші місяці

    return month;
}

// Перевантаження постфіксної операції --
MonthOfYear operator--(MonthOfYear& month, int) {
    MonthOfYear oldMonth = month; //зберігаємо попередній місяць
    operator--(month); //викликаємо попередню функцію

    return oldMonth; //повертаємо попередній місяць
}

//Отримання назв місяців року на англійській мові
const char* getMonthTitleEng(MonthOfYear month) {
    return MonthTitleEng[month - 1];
}

int main() {
    MonthOfYear month = MonthOfYear::Oct;

    //Префіксні операції ++ та --
    std::cout << "Результати виконання префіксних операцій:\n";

    for (int i = 1; i <= 8; i++) {
        if (i <= 4) {
            std::printf("%s -> ++month\n", getMonthTitleEng(month));
            ++month;
        } else {
            std::printf("%s -> --month\n", getMonthTitleEng(month));
            --month;
        }
    }

    //Постфіксні операції ++ та --
    std::cout << "\nРезультати виконання постфіксних операцій:\n";

    for (int i = 1; i <= 8; i++) {
        if (i <= 4) {
            std::printf("%s -> month++\n", getMonthTitleEng(month));
            month++;
        } else {
            std::printf("%s -> month--\n", getMonthTitleEng(month));
            month--;
        }
    }

    return 0;
}
