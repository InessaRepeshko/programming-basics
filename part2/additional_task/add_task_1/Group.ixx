export module group;

import std;
import student;

using std::string;
using std::vector;

//Class for group representation
export class Group {
    //Overloaded output operation on a stream
    //Print the group data and the list of students
    friend std::ostream& operator<<(std::ostream& out, const Group& group);

private:
    //Initialise variables to prevent undefined behaviour when creating class objects
    string number = "";
    vector<Student> students = { };

public:
    //Constrcuctors
    Group() { }
    Group(string number) : number(number) { }
    Group(const char* number) : number(number) { }

    //Setters and getters
    void setNumber(const char* number) { this->number = number; }
    void setNumber(string number) { this->number = number; }
    string getNumber() const { return number; }

    //Overloaded operator for getting vector elements
    Student operator[](int index) const { return students.at(index); }

    //Add students to the group at the end of the list
    void addStudent(Student student);

    //Select students with an even Surname length
    void selectStudentsWithEvenSurnameLength();

    //Sort students by descending order of the product of scores
    void sortByDescGradeMultiplier();
};
