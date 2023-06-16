module student;

import group;

//Overloaded output operation on a stream
//Print the students data
std::ostream& operator<<(std::ostream& out, const Student& student) {
    out << "Group ID: " << student.group->getNumber() << "\t";
    out << "Student ID: " << student.ID_number << "\t";
    out << "Surname: " << student.surname << "\t";
    out << "Grades: ";

    for (const int& grade : student.grades) {
        out << grade << "\t";
    }

    out << "\n";

    return out;
}
