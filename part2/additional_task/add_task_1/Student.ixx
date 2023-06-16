export module student;

import std;

using std::string;
using std::vector;

export class Group;

//Class for student representation
export class Student {
    //Overloaded output operation on a stream
    //Print the students data
    friend std::ostream& operator<<(std::ostream& out, const Student& student);

private:
    //Initialise variables to prevent undefined behaviour when creating class objects
    unsigned int ID_number = 0;
    string surname = "";
    vector<int> grades = { };

    //Pointer to the object group
    Group* group = nullptr;

public:
    //Constrcuctors
    Student() { }
    Student(unsigned int ID_number, const char* surname, vector<int> grades) :
        ID_number(ID_number), surname(surname), grades(grades) { }
    Student(unsigned int ID_number, string surname, vector<int> grades) :
        ID_number(ID_number), surname(surname), grades(grades) { }

    //Setters and getters
    void setID_number(unsigned int ID_number) { this->ID_number = ID_number; }
    unsigned int getID_number() const { return ID_number; }

    void setSurname(const char* surname) { this->surname = surname; }
    void setSurname(string surname) { this->surname = surname; }
    string getSurname() const { return surname; }

    void setGrades(vector<int> grades) { this->grades = grades; }
    vector<int> getGrades() const { return grades; }

    void setGroup(Group* group) { this->group = group; }
    Group* getGroup() const { return group; }

    //Calculate the grade multiplier for further sorting
    unsigned long long calculateGradeMultiplier() const {
        return accumulate(grades.begin(), grades.end(), 1ll, std::multiplies<unsigned long long>());
    }
};
