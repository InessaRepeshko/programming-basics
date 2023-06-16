/* 3. Вправа для контролю
 * 1. Створити ієрархію класів "Будинок" – "Навчальний корпус".
 * Створити масив указівників і вивести в циклі дані про об'єкти різних типів. */

/* Commands to run:
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task3_control.cpp -o task3_control
./task3_control
*/

//#pragma warning(disable:4996)
#include <iostream>
#include <cstring>

class Building {
protected:
    char address[50];
    int floors;

public:
    Building(const char* address, int floors) {
        strcpy(this->address, address);
        this->floors = floors;
    }

    virtual void print() {
        std::cout << "House: " << std::endl;
        std::cout << "Address: " << address << std::endl
                << "Floors: " << floors << "\n" << std::endl;
    }

    virtual ~Building() { }
};

class SchoolBuilding : public Building {
private:
    int offices;

public:
    SchoolBuilding(const char* address, int floors, int offices) : Building(address, floors) {
        this->offices = offices;
    }

    virtual void print() override {
        std::cout << "Educational hull: " << std::endl;
        std::cout << "Address: " << address << std::endl
                << "Floors: " << floors << std::endl
                << "Offices: " << offices << std::endl;
    }
};

int main() {
    const int N = 2;
    Building* buildings[N] = {
            new Building("2 Tsentralna St.", 2),
            new SchoolBuilding("18 Shevchenka St.", 5, 50),
    };

    //Call the print() function for each element of the array of pointers to buildings[]
    for (int i = 0; i < N; i++) {
        buildings[i]->print();
    }

    //Delete each object pointed to by an element of the buildings[] array
    for (int i = 0; i < N; i++) {
        delete buildings[i];
    }

    return 0;
}
