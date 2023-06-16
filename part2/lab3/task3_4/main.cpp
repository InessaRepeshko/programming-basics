/* 3.4 Узагальнений клас для представлення двовимірного масиву
 * Переробити клас, створений у завданні 2.4 попередньої лабораторної роботи, на шаблон класу.
 * Реалізувати зовнішню узагальнену функцію знаходження мінімального елемента масиву.
 * В функції main() створити масиви цілих, дійсних і простих дробів (раніше створений клас).
 * Для цих трьох масивів здійснити перевірку роботи функції знаходження мінімального значення серед елементів масиву,
 * здійснити тестування всіх можливостей класу з перехопленням можливих винятків,
 * а також розв'язати індивідуальну задачу.
 * Примітка: для того, щоб можна було знаходити мінімальне значення у масиві дробів,
 * у класі "Простий дріб" необхідно перевантажити операції порівняння.
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
 *
 * У функції main() здійснити тестування всіх можливостей класу з перехопленням можливих винятків,
 * а також розв'язати індивідуальну задачу. */

/* Commands to run:
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic main.cpp -o task3_4
./task3_4
*/

#include "matrix.h"
#include "fraction.h"

//Individual task realisation:
//All positive elements with even values should be doubled
template<typename someType> void elemConversion(Matrix<someType>& matrix) {
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            //The std::floor() function finds the largest integer that is not greater than the specified real number
            //check if the number is an integer
            if (std::floor(matrix(i, j)) == matrix(i, j)
                && static_cast<int>(matrix(i, j)) % 2 == 0
                && static_cast<int>(matrix(i, j)) >= 0) {
                matrix(i, j) *= 2;
            }
        }
    }
}

//Individual task realisation for fractions:
//All positive elements with even values should be doubled
template<> void elemConversion(Matrix<Fraction>& matrix) {
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            //fraction value:
            double temp = static_cast<double>(matrix(i, j).getNumerator()) /
                    static_cast<double>(matrix(i, j).getDenominator());

            if (std::floor(temp) == temp
                && static_cast<int>(temp) % 2 == 0
                && static_cast<int>(temp) >= 0 ) {
                matrix(i, j) = matrix(i, j) + matrix(i, j);
            }
        }
    }
}

//Template function for finding the minimum element among the elements of the matrix
template<typename someType> someType findMinValue(Matrix<someType> &matrix) {
    someType min = matrix(0, 0);

    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            if (matrix(i, j) < min) {
                min = matrix(i, j);
            }
        }
    }

    return min;
}

int main() {
    //Testing exception InvalidMatrixSize
    try {
        cout << "Creating a int Matrix with size of (-6)x2:\n";
        Matrix<int> matrix_test(-6, 1);
    }
    catch (const Matrix<int>::InvalidMatrixSize& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    cout << endl;

    cout << "Creating a double Matrix 1 with size of 3x2:\n";
    Matrix<double> matrix1(3, 2);
    cout << "Enter double values for Matrix 1:\n";
    cin >> matrix1;
    cout << endl;

    cout << "The minimum value of double Matrix 1: " << findMinValue(matrix1) << "\n\n";

    //Individual task
    cout << "Doubling the values of all positive even elements of Matrix 1:\n";
    elemConversion(matrix1);
    cout << "Matrix 1:\n";
    cout << matrix1;
    cout << endl;

    cout << "Creating a double Matrix 2 with size of 3x2:\n";
    Matrix<double> matrix2(3, 2);
    cout << "Enter other double values for Matrix 2:\n";
    cin >> matrix2;
    cout << endl;

    cout << "Creating a double Matrix 3 with size of 2x3:\n";
    Matrix<double> matrix3(2, 3);
    cout << "Enter double values for Matrix 3:\n";
    cin >> matrix3;

    cout << endl;

    //Testing exception IndexOutOfRange
    try {
        cout << "Refer to the element[4][5] of Matrix 3:\n";
        matrix3(4, 5);
    }
    catch (const Matrix<double>::IndexOutOfRange& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    cout << endl;

    //Testing the addition operation(double)
    cout << "Matrix 1 + Matrix 2:\n";
    cout << matrix1 + matrix2 << endl;

    //Testing the subtraction operation(double)
    cout << "Matrix 1 - Matrix 2:\n";
    cout << matrix1 - matrix2 << endl;

    //Testing the product operation(double)
    cout << "Matrix 1 * Matrix 3:\n";
    Matrix<double> matrix_multiplication_1_3 = matrix1 * matrix3; //using copy constructor
    cout << matrix_multiplication_1_3 << endl;

    //Testing exception SizeMismatchException
    try {
        cout << "Matrix 1 * Matrix 2:\n";
        cout << matrix1 * matrix2 << endl;
    }
    catch (const Matrix<double>::SizeMismatchException& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    //Individual task
    cout << endl;
    cout << "Creating an int Matrix 4 with size of 4x4:\n";
    Matrix<int> matrix4(4, 4);
    cout << "Enter integer values for Matrix 4:\n";
    cin >> matrix4;
    cout << endl;

    cout << "The minimum value of int Matrix 4: " << findMinValue(matrix4) << "\n\n";

    cout << "Doubling the values of all positive even elements of Matrix 4:\n";
    elemConversion(matrix4);
    cout << "Matrix 4:\n";
    cout << matrix4;
    cout << endl;

    cout << "Creating a Matrix 5 with fractions with size of 2x2:\n";
    Matrix<Fraction> matrix5(2, 2);
    matrix5(0, 0) = Fraction(2, 5);
    matrix5(0, 1) = Fraction(2, 5);
    matrix5(1, 0) = Fraction(-2, 5);
    matrix5(1, 1) = Fraction(2, 5);

    cout << "Matrix 5:\n";
    cout << matrix5;

    cout << "The minimum value of Matrix 5 with fractions: " << findMinValue(matrix5) << "\n\n";

    cout << "Creating a Matrix 6 with fractions with size of 2x2:\n";
    Matrix<Fraction> matrix6(2, 2);
    matrix6(0, 0) = Fraction(1, 10);
    matrix6(0, 1) = Fraction(-3, 10);
    matrix6(1, 0) = Fraction(-2, 5);
    matrix6(1, 1) = Fraction(3, 10);

    cout << "Matrix 6:\n";
    cout << matrix6;
    cout << endl;

    //Testing the addition operation(fractions)
    cout << "Matrix 5 + Matrix 6:\n";
    cout << matrix5 + matrix6 << endl;

    //Testing the subtraction operation(fractions)
    cout << "Matrix 5 - Matrix 6:\n";
    cout << matrix5 - matrix6 << endl;

    //Testing the product operation(fractions)
    cout << "Matrix 5 * Matrix 6:\n";
    Matrix<Fraction> matrix_multiplication_5_6 = matrix5 * matrix6; //using copy constructor
    cout << matrix_multiplication_5_6 << endl;

    //Testing exception DevisionByZero
    try {
        cout << "Creating a fraction 10/0:\n";
        Fraction fractionTest(10, 0);
    }
    catch(const Fraction::DevisionByZero & e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    cout << "Creating a Matrix 7 with fractions with size of 2x2:\n";
    Matrix<Fraction> matrix7(2, 2);
    matrix7(0, 0) = Fraction(10, 5);
    matrix7(0, 1) = Fraction(2, 5);
    matrix7(1, 0) = Fraction(-10, 5);
    matrix7(1, 1) = Fraction(4, 7);

    cout << "Matrix 7:\n";
    cout << matrix7;

    //Individual task
    cout << "Doubling the values of all positive even elements of Matrix 7:\n";
    elemConversion(matrix7);
    cout << "Matrix 7:\n";
    cout << matrix7;
    cout << endl;

    return 0;
}
