/* 4.3 Підрахунок кількості повторень значень (додаткове завдання)
 * Розробити програму, в якій зчитуються цілі значення і підраховується число повторень кожного значення,
 * за винятком чисел, зазначених у списку.
 * Підрахунок числа повторень числа реалізовувати за допомогою асоціативного масиву,
 * список чисел для виключення реалізовувати за допомогою множини.
 * Кожен раз, коли зустрілося число зі списку, виводити повідомлення.*/

/* Commands to run:
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task4_3.cpp -o task4_3
./task4_3
*/

//Counting the number of repetitions of values
#include <iostream>
#include <map>
#include <set>
#include <fstream>

using std::map;
using std::set;
using std::ifstream;
using std::cout;

int main() {
    //Associative array to store the number of repetitions of each value
    map<int, int> occurrences;
    //Set of numbers that will be excluded from the repetition count
    set<int> exclusionList = { 3, 7, 10, 12, 90 };

    ifstream in("data.txt");

    if (!in) {
        //print a message if the file could not be opened
        cout << "Cannot open the file." << std::endl;
        return 1;
    }

    int value;

    while (in >> value) {
        //check if the value should be excluded
        if (exclusionList.count(value) != 0) {
            cout << "A number from the list of exceptions was encountered: " << value << "\n";
        }
        //increment the repetition counter for this value
        else {
            occurrences[value]++;
        }
    }

    std::cout << "\nResults of counting repetitions:" << std::endl;

    //Iterate over the elements of the associative array
    for (auto it = occurrences.begin(); it != occurrences.end(); it++) {
        cout << "Value " << it->first << " with number of repetitions " << it->second << std::endl;
    }

    return 0;
}
