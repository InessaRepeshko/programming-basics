/* 4.2 Вектор векторів для представлення двовимірного масиву
 * Розв'язати завдання 2.4 лабораторної роботи №2 (Клас для представлення двовимірного масиву),
 * створивши клас, полем якого є вектор векторів Стандартної бібліотеки.
 * Створений клас не вимагає наявності конструктора копіювання, деструктора і перевантаженої операції присвоєння,
 * тому що не відбувається розміщення даних у динамічній пам'яті (за це відповідають вектори).
 *
 * Умова завдання 2.4 лабораторної роботи № 2:
 * 2.4 Клас для представлення двовимірного масиву
 * Розробити клас для представлення двовимірного масиву (матриці) цілих чисел довільних розмірів.
 * Створити конструктори та деструктор, перевантажити операції додавання,
 * віднімання і множення (згідно з правилами роботи з матрицями),
 * звертання за індексом, введення з потоку та виведення в потік.
 * Створити власні класи винятків та генерувати відповідні об'єкти-винятки, якщо неможливо виконати ту чи іншу операцію.
 * Створити окрему функцію, яка отримує посилання на матрицю і виконує над масивом дії, вказані в таблиці.
 * Функція не повинна бути методом класу або дружньою функцією.
 *
 * Умова індивідуального завдання:
 * Номер варіанту (номер студента у списку): 25.
 * Правило перетворення елементів масиву: Всі додатні елементи з парними значеннями повинні бути збільшені у два рази.
 * У функції main() здійснити тестування всіх можливостей класу з перехопленням можливих винятків,
 * а також розв'язати індивідуальну задачу. */

/* Commands to run:
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task4_2.cpp -o task4_2
./task4_2
*/

//Class for representing a two-dimensional array
#include <iostream>
#include <exception>
#include <vector>

using std::vector;
using std::istream;
using std::ostream;
using std::exception;
using std::cout;
using std::cin;
using std::endl;

class Matrix {
    //Overloaded output operation on a stream
    friend ostream& operator<<(ostream& out, const Matrix& matrix);
    //Overloaded input operation
    friend istream& operator>>(istream& in, Matrix& matrix);
private:
    vector<vector<int>> data;
public:
    //Exception class to handle errors related to matrix index exceeding its dimensions
    class IndexOutOfRange : public exception {
        virtual const char* what() const throw() {
            return "Matrix index out of range.";
        }
    };

    //Exception class for matrix sizes
    class InvalidMatrixSize : public exception {
        virtual const char* what() const throw() {
            return "Invalid matrix size.";
        }
    };

    //Exception class to handle errors related to matrix size mismatch in operations
    class SizeMismatchException : public exception {
    public:
        virtual const char* what() const throw() {
            return "Size Mismatch Exception.";
        }
    };
    //Constrcuctors:
    //The constructor without parameters:
    Matrix() {}
    Matrix(int rows, int cols);

    //Getters:
    int getRows() const { return data.size(); }
    int getCols() const {
        if (data.empty())
            return 0;
        return data[0].size();
    }

    //Overload the operation of a function call
    int& operator()(int row, int col);
    //Overloading operations + , -, *
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

};

//The constructor with 2 parameters
Matrix::Matrix(int rows, int cols) {
    if (rows <= 0
        || cols <= 0) {
        throw InvalidMatrixSize();
    }

    data = vector<vector<int>>(rows, vector<int>(cols));
}

//Matrix element access operator
int& Matrix::operator()(int row, int col) {
    if (row >= getRows()
        || col >= getCols()
        || row < 0
        || col < 0) {
        throw IndexOutOfRange();
    }

    return data[row][col];
}

//Overloading operation +
Matrix Matrix::operator+(const Matrix& other) const {
    //Checking that the matrix sizes are appropriate for their addition
    if (getRows() != other.getRows()
        || getCols() != other.getCols()) {
        throw SizeMismatchException();
    }

    Matrix result(getRows(), getCols());

    for (int i = 0; i < getRows(); i++) {
        for (int j = 0; j < getCols(); j++) {
            result.data[i][j] = this->data[i][j] + other.data[i][j];
        }
    }

    return result;
}

//Overloading operations -
Matrix Matrix::operator-(const Matrix& other) const {
    //Checking that the matrix sizes are appropriate for their subtraction
    if (getRows() != other.getRows()
        || getCols() != other.getCols()) {
        throw SizeMismatchException();
    }

    Matrix result(getRows(), getCols());
    for (int i = 0; i < getRows(); i++) {
        for (int j = 0; j < getCols(); j++) {
            result.data[i][j] = this->data[i][j] - other.data[i][j];
        }
    }

    return result;
}

//Overloading operations *
Matrix Matrix::operator*(const Matrix& other) const {
    //Checking that the matrix sizes are appropriate for their multiplication
    if (getRows() != other.getCols()
        || getCols() != other.getRows()) {
        throw SizeMismatchException();
    }

    Matrix result(getRows(), other.getCols());

    for (int i = 0; i < getRows(); i++) {
        for (int j = 0; j < other.getCols(); j++) {
            int sum = 0;

            for (int k = 0; k < getCols(); k++) {
                sum += data[i][k] * other.data[k][j]; //cols = other.rows
            }

            result.data[i][j] = sum;
        }
    }

    return result;
}

istream& operator>>(istream& in, Matrix& matrix) {
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            in >> matrix.data[i][j];
        }
    }

    return in;
}

ostream& operator<<(ostream& out, const Matrix& matrix) {
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            out << matrix.data[i][j] << "\t";
        }
        out << "\n";
    }

    return out;
}

//Individual task realisation
void elemConversion(Matrix& matrix) {
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            if (matrix(i, j) % 2 == 0
                && matrix(i, j) >= 0) {
                matrix(i, j) *= 2;
            }
        }
    }
}

int main() {
    //Testing exception InvalidMatrixSize
    try {
        cout << "Creating Matrix [6x(-2)]:\n";
        Matrix matrix_test(6, -2);
    }
    catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    cout << endl;

    cout << "Creating Matrix1 [3x2]:\n";
    Matrix matrix1(3, 2);
    cout << "Enter values for Matrix1:\n";
    cin >> matrix1;
    cout << "Matrix1:\n";
    cout << matrix1;
    cout << endl;

    cout << "Creating Matrix2 [3x2]:\n";
    Matrix matrix2(3, 2);
    cout << "Enter other values for Matrix2:\n";
    cin >> matrix2;
    cout << "Matrix2:\n";
    cout << matrix2;
    cout << endl;

    cout << "Creating Matrix3 [2x3]:\n";
    Matrix matrix3(2, 3);
    cout << "Enter values for Matrix3:\n";
    cin >> matrix3;
    cout << "Matrix3:\n";
    cout << matrix3;
    cout << endl;

    //Testing exception IndexOutOfRange
    try {
        cout << "Refer to the element[2][5] of Matrix3:\n";
        matrix3(2, 5);
    }
    catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    cout << endl;

    //Testing the addition operation
    cout << "Matrix1 + Matrix2:\n";
    cout << matrix1 + matrix2 << endl;

    //Testing the subtraction operation
    cout << "Matrix1 - Matrix2:\n";
    cout << matrix1 - matrix2 << endl;

    //Testing the product operation
    cout << "Matrix1 * Matrix3:\n";
    Matrix matrix_multiplication_1_3 = matrix1 * matrix3; //using copy constructor
    cout << matrix_multiplication_1_3 << endl;

    //Testing exception SizeMismatchException
    try {
        cout << "Matrix 1 * Matrix 2:\n";
        cout << matrix1 * matrix2 << endl;
    }
    catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    //Individual task
    cout << endl;
    cout << "Creating Matrix4 [4x4]:\n";
    Matrix matrix4(4, 4);
    cout << "Enter values for Matrix4:\n";
    cin >> matrix4;
    cout << "Matrix4:\n";
    cout << matrix4;
    cout << endl;
    cout << "Doubling the values of positive even elements for Matrix4:\n";
    elemConversion(matrix4);
    cout << "Matrix4:\n";
    cout << matrix4;

    return 0;
}
