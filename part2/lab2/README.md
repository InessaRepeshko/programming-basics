## Laboratory Training № 2 "Creation and Use of C++ Classes"

## 2.1 Class for Representing a Point in Three-Dimensional Space

Create a class for representing a point in three-dimensional space (3D points). The class must meet the following requirements:
* have a constructor without parameters;
* have a constructor with three parameters;
* contain data members of double type to represent the coordinates of a point;
* implement public data access functions (setters and getters).

To calculate the distance, create an operator function operator-() ("minus") with two parameters (3D points) and a result of type double. Declare this function as a friend of the class.

In the main() function, you should create two objects of 3D point type by applying different constructors. Use access functions to set and read values. Calculate the distance between two points by using the minus operation, then change the coordinates of one of the points and calculate the distance between the two points by explicitly calling the operator-() function.

## 2.2 Class for Representing a Simple Fraction

Create a class that represents a simple fraction. Implement constructors, a function for reduction of fractions, and overload operations +, -, *, /, <, <=, >, >=, as well as stream input and output. In the output operator function, implement the most correct output: get and output the whole part for improper fractions, do not output the denominator if it is equal to 1 or the numerator is equal to 0, etc.

Demonstrate class features in the main() function.

Read two fractions and demonstrate the reduction of fractions and all overloaded operations in the main() function.

Note: you should not store the integer part of the fraction separately, since it can always be calculated from the numerator and denominator.

## 2.3 Classes for Representing Students and Groups

Create classes for presenting data about students and groups of students. The "Student" class should contain the following private data members:
* student ID number (unsigned int);
* last name (pointer to character); the corresponding string will be created in a free store as needed;
* grades for the last session in the form of an array of integers from 0 to 100 (grades by subject); an array should be created in a free store;
* a pointer to an object of class "Group".

Define the following members in the "Student" class:
* constructor without parameters and constructor with parameters;
* copy constructor;
* destructor;
* data access functions (setters and getters);
* overloaded assignment operator.

The operator function of output data about the student to the stream should be implemented as an external function (class friend). To ensure sorting, overload the necessary comparison (relation) operator functions.

A constant should be defined for the maximum possible number of students (for example, 50)

The following data elements should be defined in the "Group" class:
* group index;
* an array of pointers to students of the maximum possible length;
* the actual number of pointers in the array.

Define the following elements in the "Group" class:
* constructor without parameters and constructor with parameters;
* group index data access functions (setter and getter);
* overloaded assignment operator;
* the function of sorting according to the specified criterion;
* finding students by certain attribute.

Instead of a getter for an array of pointers, you can overload the subscript operator of getting an item by index. In addition, an operator function of output data is required.

In the main() function, create a "Group" object, add an array of students and demonstrate all implemented functions, in particular, sorting and searching by attribute.

## 2.4 Class for Representing a Two-Dimensional Array

Develop a class to represent two-dimensional array of integers (matrix) of arbitrary size. Create constructors and destructors, overload operations of addition, subtraction and multiplication (according to the rules of working with matrices), getting items by index, as well as stream input and output. Create your own exception classes and generate relevant objects, if it is impossible to perform a particular operation.

Create a separate function that gets reference to an array and performs actions listed in the table. The function should not be friend or member function.

Individual task for variant 25:

![var25](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab2/screens/var25.png)

Demonstrate all class features in the main() function. Solve individual task with catching of possible exceptions.

## 2.5 Calculation of the Sum of Entered Values

Create a class with a private data member, getter, and constructor with one argument. This class also should contain a static private data member that stores the sum of all data members of previously created objects. Each call of the constructor includes adding of a new value to the static field. Public static function of the same class should return this sum.

The main() function should contain creation of several objects and output of the calculated sum.

## Control exercise

№ 4. Create a class "Quadratic equation" with data members (coefficients of the equation), necessary constructors and access functions. Implement a function of finding the roots.


## Commands to run
```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_1.cpp -o task2_1
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_2.cpp -o task2_2
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_3.cpp -o task2_3
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_4.cpp -o task2_4
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_5.cpp -o task2_5
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_control.cpp -o task2_control
./task2_1
./task2_2
./task2_3
./task2_4
./task2_5
./task2_control
```


## Examples of program results
```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_1.cpp -o task2_1
./task2_1
```
![task2_1](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab2/screens/task2_1.png)

```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_2.cpp -o task2_2
./task2_2
```
![task2_2](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab2/screens/task2_2.png)

```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_3.cpp -o task2_3
./task2_3
```
![task2_3](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab2/screens/task2_3.png)

```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_4.cpp -o task2_4
./task2_4
```
![task2_4](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab2/screens/task2_4.png)

```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_5.cpp -o task2_5
./task2_5
```
![task2_5](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab2/screens/task2_5.png)

```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_control.cpp -o task2_control
./task2_control
```
![task2_control](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab2/screens/task2_control.png)

© Inessa Repeshko. 2023
