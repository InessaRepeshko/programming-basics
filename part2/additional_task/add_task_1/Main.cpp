/* Додаткове завдання № 1: Представлення й обробка даних про студентів
 * з використанням засобів Стандартної бібліотеки шаблонів, модулів та лямбда-виразів.
 * Виконати завдання 1.1 лабораторної роботи №4 (Класи для представлення студента і групи)
 * з використанням засобів Стандартної бібліотеки шаблонів, модулів та лямбда-виразів.
 * Класи для представлення студента і групи розташувати в окремих модулях.
 * Замість підключення заголовних файлів використовувати імпорт з модулів. */

import std;
import student;
import group;

using std::vector;

int main() {
    //Create initial data about the group and students
    std::cout << "Creating Group:" << std::endl;
    Group group("KN-222b");
    group.addStudent(Student(222001, "Chyzhin", vector<int>{ 100, 90, 80, 80, 80 }));
    group.addStudent(Student(222002, "Boyko", vector<int>{ 60, 90, 100, 80, 80 }));
    group.addStudent(Student(222003, "Drozd", vector<int>{ 100, 80, 90, 80, 85 }));
    group.addStudent(Student(222004, "Fadeeva", vector<int>{ 95, 95, 95, 80, 95 }));
    group.addStudent(Student(222005, "Molozhenko", vector<int>{ 90, 90, 90, 90, 90 }));
    group.addStudent(Student(222006, "Chyzhy", vector<int>{ 100, 100, 100, 100, 100 }));

    //Print the initial group data
    std::cout << "Group with initial list of students:\n";
    std::cout << group << std::endl;

    //Print the data of the 4-th student in the order of the group
    std::cout << "Student data according to the index group[3]:\n";
    std::cout << group[3] << std::endl;

    //Sort students by descending order of the product of scores and print sorted student list
    group.sortByDescGradeMultiplier();
    std::cout << "Group with sorted list of students by descending order of the product of scores:\n";
    std::cout << group << std::endl;

    //Select students with an even Surname length and print selected student list
    std::cout << "Students with an even Surname length:\n";
    group.selectStudentsWithEvenSurnameLength();

    return 0;
}
