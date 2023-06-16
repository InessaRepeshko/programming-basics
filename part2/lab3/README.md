## Laboratory Training № 3 "Using Polymorphism and Templates"

## 3.1 The Hierarchy of Classes

Implement classes "Human," "Citizen", "Student", and "Employee". Each class must implement virtual function that shows related data on the screen. Create an array of pointers to different objects of the class hierarchy. Create a cycle and display data that represents objects of different types.

## 3.2 Using Polymorphism for Callback

Create a class for solving problem set in task 1.2 of the sixth laboratory training from previous semester. The class should contain at least two member functions: a function that returns some value according to individual task, and pure virtual function that is called from the previous one and defines the left side of the equation or researched function (according to the task).

Class should be allocated in a separate header file. The relevant implementation file should contain the definition of non-abstract member functions.

Another translation unit should contain a class derived from the previous one. This class should contain the definition of the virtual function, which is a subject of investigation. Create an object of the derived class and implement the individual task in main() function.

Note: You should add some base class member functions that will calculate the first (second) derivative.

## 3.3 Using Templates for Callback

In a separate header file, create a template function for solving task 1.2 of the sixth laboratory training of the previous semester. The first parameter of the function must be an object of the template type to which the parentheses operation can be applied.

Check the operation of the template on two functions that are subject to research. One of the functions must be implemented as a functional object.

Note: To calculate the first (second) derivative, separate template functions should be added.

## 3.4 Class Template for Representation of Two-Dimensional Array

Convert class created in the task 1.4 of the previous laboratory training into class template. Implement global template function that returns minimum array item. Create arrays of integers, real numbers, and simple fractions (previously created class) in main() function. For these three arrays you should test the function of finding the minimum value, as well as other class features with catching possible exceptions. You should also solve the problem from the individual task.

Note: in order to be able to find the minimum value in the array of fractions you should overload comparison operation for objects of the class "Simple fraction".

## 3.5 Library of Template Functions for Working with an Array (Additional Task)

Create a header file with functions that work with an array of an arbitrary generic type. The following functions should be implemented:
* exchange of places of elements with the specified indexes;
* search for an element with a certain value;
* exchange of places of all pairs of adjacent elements (with even and odd index).

Demonstrate the operation of all functions using at least three different types of data.

## Control exercise

№ 1. Create a hierarchy of classes "Building" - "Educational building". Create an array of pointers and display in a cycle data that represents objects of different types.


## Commands to run
```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task3_1.cpp -o task3_1
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic source.cpp main.cpp -o task3_2
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic main.cpp -o task3_3
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic main.cpp -o task3_4
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic main.cpp -o task3_5
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task3_control.cpp -o task3_control
./task3_1
./task3_2
./task3_3
./task3_4
./task3_5
./task3_control
```


## Examples of program results
```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task3_1.cpp -o task3_1
./task3_1
```
![task3_1](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab3/screens/task3_1.png)

```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic source.cpp main.cpp -o task3_2
./task3_2
```
![task3_2](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab3/screens/task3_2.png)

```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic main.cpp -o task3_3
./task3_3
```
![task3_3](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab3/screens/task3_3.png)


```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic main.cpp -o task3_4
./task3_4
```
![task3_4](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab3/screens/task3_4.png)

```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic main.cpp -o task3_5
./task3_5
```
![task3_5](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab3/screens/task3_5.png)

```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task3_control.cpp -o task3_control
./task3_control
```
![task3_control](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab3/screens/task3_control.png)

© Inessa Repeshko. 2023
