/* 4. Вправа для контролю
 * 2. Занести дані про студентів групи в контейнер multimap.
 * Ключем є прізвище, значенням - ім'я.
 * В групі можуть бути однопрізвищники.
 * Видати повідомлення, якщо в групі є однопрізвищники.
 * Видати дані про студентів групи за алфавітом прізвищ. */

/* Commands to run:
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task4_control.cpp -o task4_control
./task4_control
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    multimap<string, string> students;

    //Adding student data
    students.insert(make_pair("Chyzhin", "Dmytro"));
    students.insert(make_pair("Molozhenko", "Yana"));
    students.insert(make_pair("Boyko", "Denis"));
    students.insert(make_pair("Drozd", "Olga"));
    students.insert(make_pair("Fadeeva", "Vanessa"));
    students.insert(make_pair("Molozhenko", "Alexander"));

    //Check for people with the same Surname
    for (auto it = students.begin(); it != students.end(); it++) {
        if (students.count(it->first) > 1) {
            cout << "There are students with the same Surname in the group.\n" << endl;
            break;
        }
    }

    //Print data about students by Surname alphabet
    cout << "Students are listed in alphabetical order by Surname:" << endl;

    for (auto it = students.begin(); it != students.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
