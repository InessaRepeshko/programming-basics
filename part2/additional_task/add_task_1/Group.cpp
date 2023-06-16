module group;

//Overloaded output operation on a stream
//Print the group data and the list of students
std::ostream& operator<<(std::ostream& out, const Group& group) {
    out << "Group ID: " << group.number << "\n";
    out << "Number of students: " << group.students.size() << "\n";
    out << "Student list: " << "\n";

    for (const Student& student : group.students) {
        out << student;
    }

    return out;
}

//Add students to the group at the end of the list
void Group::addStudent(Student student) {
    student.setGroup(this);
    students.push_back(std::move(student));
}

//Select students with an even Surname length and print selected student list
void Group::selectStudentsWithEvenSurnameLength() {
    for_each(students.begin(),
             students.end(),
             [](const Student& student) {
                    if (student.getSurname().length() % 2 == 0 ) {
                        std::cout << student;
                    }
             }
             );
}

//Sorting by decreasing average score
void Group::sortByDescGradeMultiplier() {
    sort(students.begin(),
         students.end(),
         [](const Student& st1, const Student& st2) {
                return st1.calculateGradeMultiplier() > st2.calculateGradeMultiplier();
         }
         );
}
