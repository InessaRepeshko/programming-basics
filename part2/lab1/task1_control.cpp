/* 1. Вправа для контролю.
 1. Визначити перелік для представлення сезонів року.
 Реалізувати та продемонструвати перевантаження операцій ++ і --. */

/* Commands to run:
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task1_control.cpp -o task1_control
./task1_control
*/

#include <iostream>

const int numberOfSeasons = 4;

// Для можливості масштабування в майбутньому створимо окремий масив із назвами сезонів року на англійській мові.
const char* SeasonsTitleEng[] = {
        "Winter",
        "Spring",
        "Summer",
        "Autumn"
};

// Іменований перелік сезонів року.
enum SeasonsOfYear {
    Win = 1, Spr, Sum, Aut
};

// Перевантаження префіксної операції ++.
SeasonsOfYear operator++(SeasonsOfYear& season) {
    season = (season == SeasonsOfYear::Aut) ? SeasonsOfYear::Win : (SeasonsOfYear) (season + 1);
    //умова true - окремий випадок, false - всі інші сезони

    return season;
}

// Перевантаження постфіксної операції ++.
SeasonsOfYear operator++(SeasonsOfYear& season, int) {
    SeasonsOfYear oldSeason = season; //зберігаємо попередній сезон
    operator++(season); //викликаємо попередню функцію

    return oldSeason; //повертаємо попередній сезон
}

// Перевантаження префіксної операції --.
SeasonsOfYear operator--(SeasonsOfYear& season) {
    season = (season == SeasonsOfYear::Aut) ? SeasonsOfYear::Win : (SeasonsOfYear) (season - 1);
    //умова true - окремий випадок, false - всі інші сезони

    return season;
}

// Перевантаження постфіксної операції --.
SeasonsOfYear operator--(SeasonsOfYear& season, int) {
    SeasonsOfYear oldSeason = season; //зберігаємо попередній сезон
    operator--(season); //викликаємо попередню функцію

    return oldSeason; //повертаємо попередній сезон
}

// Отримання назви пори року на англійській мові.
const char* getSeasonTitleEng(SeasonsOfYear season) {
    return SeasonsTitleEng[season - 1];
}

int main() {
    SeasonsOfYear season = SeasonsOfYear::Win;

    //Префіксні операції ++ та --
    std::cout << "Результати виконання префіксних операцій:\n";

    for (int i = 1; i <= numberOfSeasons; i++) {
        if (i <= 2) {
            std::printf("%s -> ++season\n", getSeasonTitleEng(season));
            ++season;
        } else {
            std::printf("%s -> --season\n", getSeasonTitleEng(season));
            --season;
        }
    }

    //Постфіксні операції ++ та --
    std::cout << "\nРезультати виконання постфіксних операцій:\n";

    for (int i = 1; i <= numberOfSeasons; i++) {
        if (i <= 2) {
            std::printf("%s -> season++\n", getSeasonTitleEng(season));
            season++;
        } else {
            std::printf("%s -> season--\n", getSeasonTitleEng(season));
            season--;
        }
    }

    return 0;
}
