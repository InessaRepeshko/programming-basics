/* 4.1 Представлення й обробка даних про студентів з використанням засобів Стандартної бібліотеки шаблонів
 * Виконати завдання 2.3 лабораторної роботи №2 (Класи для представлення студента і групи).
 * У класі "Студент" для зберігання прізвища застосувати рядок типу std::string.
 * Оцінки за останню сесію зберігати у векторі цілих чисел (std::vector<int>).
 * Окрім функцій, перелічених в завданні 1.3 другої лабораторної роботи, слід реалізувати функції, які здійснюють:
 * - обчислення показника, за величиною якого здійснюється сортування відповідно до індивідуального завдання;
 * - перевірку умови, яка використовується для пошуку даних відповідно до індивідуального завдання.
 * У класі "Група студентів" розташувати вектор об'єктів класу, який представляє студента.
 * Реалізувати функції, визначені в завданні 1.3 другої лабораторної роботи для цього класу.
 * Для сортування масиву за ознакою, яка наведена в індивідуальному завданні скористатися алгоритмом sort().
 * Для пошуку даних про студентів, які відповідають умові,
 * наведеній в індивідуальному завданні застосувати алгоритм for_each().
 * Додатково розмістити об'єкти класу "Студент" в черзі з пріоритетом,
 * з якої вилучати об'єкти за зменшенням середнього балу.
 *
 * Умова завдання 2.3 лабораторної роботи № 2:
 * 2.3 Класи для представлення студента і групи
 * Створити класи для представлення даних про студента і групи студентів.
 * Клас "Студент" повинен містити такі приватні елементи даних:
 * - номер студентського посвідчення (unsigned int);
 * - прізвище (вказівник на символ); відповідний рядок створюватиметься у динамічній пам'яті за необхідністю;
 * - оцінки за останню сесію у вигляді масиву цілих від 0 до 100 (оцінки за предметами);
 * масив оцінок створюється в динамічній пам'яті;
 * - вказівник на об'єкт класу "Група".
 * Визначити в класі "Студент" такі елементи:
 * - конструктор без параметрів і конструктор з параметрами;
 * - конструктор копіювання;
 * - деструктор;
 * - функції доступу до даних (сеттери й геттери);
 * - перевантажена операцію присвоєння.
 * Операторну функцію виведення даних про студента в потік слід реалізувати як зовнішню функцію – друга класу.
 * Для забезпечення сортування перевантажити необхідні функції порівняння (відношення).
 * Слід визначити константу для максимально можливої кількості студентів (наприклад, 50)
 * У класі "Група" слід визначити такі елементи даних:
 * - індекс групи;
 * - масив указівників на студентів максимально можливої довжини;
 * - реальна кількість указівників у масиві.
 * Визначити в класі "Група" такі елементи:
 * - конструктор без параметрів і конструктор з параметрами;
 * - функції доступу до даних про індекс (сеттер і геттер);
 * - перевантажена операцію присвоєння;
 * - функцію сортування за визначеним критерієм;
 * - знаходження студентів за певною ознакою.
 * Замість геттера для масиву вказівників можна перевантажити операцію отримання елемента за індексом.
 * Крім того, потрібна функція виведення в потік.
 * У функції main() створити об'єкт "Група", додати масив студентів і продемонструвати всі реалізовані функції,
 * зокрема, сортування і пошук за ознакою. */

/* Commands to run:
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task4_1.cpp -o task4_1
./task4_1
*/

//Classes for students and groups
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <queue>
using std::string;
using std::vector;
using std::priority_queue;
class Group;

//Class for student representation
class Student {
    //Overloaded output operation on a stream
    friend std::ostream& operator<<(std::ostream& out, const Student& student);

private:
    unsigned int ID_number = 0;
    string surname;
    vector<int> grades;
    Group* group = nullptr; //Pointer to the object group
    double averageGrade = 0;

public:
    //Constrcuctors:
    //The constructor without parameters
    Student() { }
    Student(unsigned int ID_number, const string &surname, const vector<int> &grades, Group* group);

    //Setters and getters:
    void setID_number(unsigned int ID_number) { this->ID_number = ID_number; }
    unsigned int getID_number() const { return ID_number; }
    void setSurname(const string& surname) { this->surname = surname; }
    const string& getSurname() const { return surname; }
    void setGrades(const vector<int>& grades) {
        this->grades = grades;
        setAverageGrade();
    }
    const vector<int>& getGrades() const { return grades; }
    void setGroup(Group* group) { this->group = group; }
    Group* getGroup() const { return group; }
    void setAverageGrade() {
        this->averageGrade = accumulate(grades.begin(), grades.end(), 0.0) / grades.size();
    }
    double getAverageGrade() const { return averageGrade; }

    bool operator<(const Student& other) const;
};

//The constructor with 4 parameters
Student::Student(unsigned int ID_number, const string& surname , const vector<int>& grades, Group* group) {
    setID_number(ID_number);
    setSurname(surname);
    setGrades(grades);
    setGroup(group);
}

//for sorting and priority_queue
bool Student::operator<(const Student& other) const {
    return averageGrade < other.averageGrade;
}

//Class for group representation
class Group {
    //Overloaded output operation on a stream
    friend std::ostream& operator<<(std::ostream& out, Group& group);

private:
    int index = 0;
    vector<Student> students;
    
public:
    //Constrcuctors:
    //The constructor without parameters
    Group() {};
    Group(int index, vector<Student>& students);

    //Setters and getters:
    void setIndex(int index) { this->index = index; }
    int getIndex() const { return index; }
    void setStudents(vector<Student>& students);

    //Sorting by increasing average score
    void sortByAverageGrade();
    //Finding students with a surname length of less than 7 letters.
    void findStudentSurnameLess10Chars();
};

//The constructor with 3 parameters
Group::Group(int index, vector<Student> &students) {
    setIndex(index);
    setStudents(students);
}

void Group::setStudents(vector<Student> &students) {
    this->students.clear();
    for (unsigned long i = 0; i < students.size(); i++) {
        this->students.push_back(students[i]);
        this->students[i].setGroup(this);
    }
}

//for Student
std::ostream& operator<<(std::ostream& out, const Student& student) {
    out << "Group ID: " << student.group->getIndex() << "\t";
    out << "Student ID: " << student.ID_number << "\t";
    out << "Surname: " << student.surname << "\t";
    out << "Grades: ";
    for (const auto &grade : student.grades) {
        out << grade << "\t";
    }
    out << "\n";
    return out;
}

//for Group
std::ostream& operator<<(std::ostream& out, Group& group) {
    out << "Group ID: " << group.index << "\n";
    out << "Number of students: " << group.students.size() << "\n";
    out << "Students: " << "\n";
    for (const auto& student : group.students) {
        out << student;
    }
    return out;
}

//Finding students with a surname length of less than 7 letters.
void Group::findStudentSurnameLess10Chars() {
    for_each(students.begin(), students.end(), [](const Student &student) {
        if (student.getSurname().length() < 10)
            std::cout << student;
    });
}

//Sorting by increasing average score
void Group::sortByAverageGrade() {
    sort(students.begin(), students.end());
}

int main() {
    std::cout << "Creating Group:" << std::endl;
    Group group1;
    vector<Student> students_gr1;
    students_gr1.push_back(Student(222001, "Chyzhin", vector<int>{ 100, 90, 80, 80, 80 }, nullptr));
    students_gr1.push_back(Student(222002, "Boyko", vector<int>{ 60, 90, 100, 80, 80 }, nullptr));
    students_gr1.push_back(Student(222003, "Drozd", vector<int>{ 100, 80, 90, 80, 85 }, nullptr));
    students_gr1.push_back(Student(222004, "Fadeeva", vector<int>{ 95, 95, 95, 80, 95 }, nullptr));
    students_gr1.push_back(Student(222005, "Molozhenko", vector<int>{ 90, 90, 90, 90, 90 }, nullptr));
    students_gr1.push_back(Student(222006, "Chyzh", vector<int>{ 100, 100, 100, 100, 100 }, nullptr));

    group1.setStudents(students_gr1);
    group1.setIndex(222);

    std::cout << "Group with initial list of students:\n";
    std::cout << group1;
    group1.sortByAverageGrade();
    std::cout << std::endl;
    std::cout << "Group with sorted list of students by average score:\n";
    std::cout << group1;
    std::cout << std::endl;
    std::cout << "Students with a surname length of less than 10 letters:\n";
    group1.findStudentSurnameLess10Chars();
    std::cout << std::endl;

    //Create priority queue of students
    priority_queue<Student> student_queue;

    //Add students to queue
    for (const auto& student : students_gr1) {
        student_queue.push(student);
    }

    //Remove students from queue in order of decreasing average grade
    std::cout << "Removing students from queue in order of decreasing average grade:\n";
    while (!student_queue.empty()) {
        std::cout << "Removing student " << student_queue.top().getID_number() << " with average grade "
                  << student_queue.top().getAverageGrade() << std::endl;
        student_queue.pop();
    }

    return 0;
}
