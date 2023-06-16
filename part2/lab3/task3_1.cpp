/* 3.1 Ієрархія класів
 * Реалізувати класи "Людина", "Громадянин", "Студент", "Співробітник".
 * В кожному класі визначити віртуальну функцію виведення даних про об'єкт на екран.
 * Створити масив указівників на різні об'єкти ієрархії.
 * В циклі для кожного об'єкта вивести на екран рядок даних про нього. */

/* Commands to run:
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task3_1.cpp -o task3_1
./task3_1
*/

//Class hierarchy
#include <iostream>
#include <cstring>

using std::cout;

//Class for human representation
//Class Human is the base class for our hierarchy
class Human {
protected:
    char* name;
    double height;
    double weight;
public:
    //Constructor that initialises all protected fields
    Human(const char* name, double height, double weight) : height(height), weight(weight) {
        this->name = new char[strlen(name) + 1]; //dynamic memory allocation for an array of characters with name
        //strcpy_s(this->name, strlen(name) + 1, name);
        strcpy(this->name, name);
    }

    //Getters
    char* getName() const { return name; };
    double getHeight() const { return height; }
    double getWeight() const { return weight; }

    //Virtual method that prints information about a human
    virtual void printInfo() {
        cout << "Name: " << name << "\n";
        cout << "Height: " << height << " cm\n";
        cout << "Weight: " << weight << " kg\n";
    }

    //Virtual destructor for correct work with dynamic memory
    virtual ~Human() {
        delete[] name;
    }
};

//Class for citizen representation
//class Citizen is a descendant of the class Human
class Citizen : public Human {
protected:
    char* nationality;
public:
    //Constructor that initialises all protected fields, including those of the base class
    Citizen(const char* name, double height, double weight, const char* nationality) : Human(name, height, weight) {
        //dynamic memory allocation for an array of characters with nationality
        this->nationality = new char[strlen(nationality) + 1];
        //strcpy_s(this->nationality, strlen(nationality) + 1, nationality);
        strcpy(this->nationality, nationality);
    }

    //Getter
    char* getNationality() const { return nationality; };

    //Overridden method for printing information
    void printInfo() override {
        //Call the base class method for printing the common human information
        Human::printInfo();
        cout << "Nationality: " << nationality << "\n";
    }

    //Overridden destructor of a base class
    ~Citizen() override {
        delete[] nationality;
    }
};

//Class for student representation
//class Student is a descendant of the class Citizen
class Student : public Citizen {
protected:
    char* university;
    int ID_number;
public:
    //Constructor that initialises all protected fields, including those of the base class
    Student(const char* name, double height, double weight, const char* nationality, const char* university, int ID_number)
            : Citizen(name, height, weight, nationality), ID_number(ID_number) {
        this->university = new char[strlen(university) + 1]; //dynamic memory allocation for an array of characters with university
        //strcpy_s(this->university, strlen(university) + 1, university);
        strcpy(this->university, university);
    }

    //Getters
    char* getUniversity() const { return university; };
    int getID_number() const { return ID_number; }

    //Overridden method for printing information
    void printInfo() override {
        //Call the base class method for printing the common citizen information
        Citizen::printInfo();
        cout << "University: " << university << "\n";
        cout << "Student ID: " << ID_number << "\n";
    }

    //Overridden destructor of a base class
    ~Student() override {
        delete[] university;
    }
};

//Class for employee representation
//class Employee is a descendant of the class Citizen
class Employee : public Citizen {
protected:
    char* company;
public:
    //Constructor that initialises all protected fields, including those of the base class
    Employee(const char* name, double height, double weight, const char* nationality,const char *company)
            : Citizen(name, height, weight, nationality) {
        this->company = new char[strlen(company) + 1]; //dynamic memory allocation for an array of characters with company
        //strcpy_s(this->company, strlen(company) + 1, company);
        strcpy(this->company, company);
    }

    //Getter
    char* getCompany() const { return company; };

    //Overridden method for printing information
    void printInfo() override {
        //Call the base class method for printing the common citizen information
        Citizen::printInfo();
        cout << "Company: " << company << "\n";
    }

    //Overridden destructor of a base class
    ~Employee() override {
        delete[] company;
    }
};

int main() {
    const int N = 4;
    //Creating an array of pointers to different hierarchy objects.
    Human* humans[N] = {
            new Human("Alex", 190.0, 77.7),
            new Citizen("Olga", 167.5, 55.5, "French"),
            new Student("Fred", 182.3, 88.8, "Ukrainian", "NTU \"KPI\"", 222001),
            new Employee("Oleg", 178.2, 99.9, "Ukrainian", "EPAM"),
    };

    cout << "Information about Humans: \n";
    for (int i = 0; i < N; i++) {
        humans[i]->printInfo();
        cout << "\n";
    }

    //Printing student ID_number(humans[2])
    cout << "Output the student ID:\nStudent ID: " << dynamic_cast<Student*>(humans[2])->getID_number() << "\n";

    for (int i = 0; i < N; i++) {
        //Deleting the object pointed to by the humans array element
        delete humans[i];
    }

    return 0;
}
