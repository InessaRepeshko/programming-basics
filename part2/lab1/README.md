## Laboratory Training № 1 "Working with Enumerations and Structures"

## 1.1 An Enumeration for Presenting the Months of the Year

Create an enumeration to represent the months of the year. Implement and demonstrate overloaded operators ++ so -- that after December there is January and before January there is December.

## 1.2 3D-Points

Create a structure to describe a 3D-point. Write a program that calculates distance between two 3D-points. To calculate the distance, create a function with two parameters of structure type to represent the points.

## 1.3 Representation and Processing Students Data

Create a structure for presenting data concerned with student. The structure should contain the following data members:
* student identity number (unsigned int);
* surname (array of characters);
* marks of the last session in the form of an array of integers from 0 to 100 (marks on subjects).

Implement a function that outputs student data to the console window. The first parameter of the function should be a structure that describes the student.

Implement functions that receive an array of pointers to student and the length of the array and execute
* array sorting according to the criterion specified in the individual task;
* searching for data about students that meet the condition given in the individual task;
* displaying all items of the array in the console window.

When sorting an array of structures, swap the elements of the array of pointers instead of swapping two structures.

Create an array of students. Create an array of pointers to students, filling it with addresses of structures from the array of students. Demonstrate sorting and searching for students.

Individual task for variant 25:

![var25](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab1/screens/var25.png)

## 1.4 Working with a Linked List

You should write a program that provides file input and output and implements an assignment of Laboratory training # 4 of the course "Programming Basics (Part 1)". You should implement following steps:
* definition of a constant (n) which determines column count of two-dimensional array
* opening file for reading (file should be prepared using some text editor)
* reading integer values until the end of file and storing them in the linked list
* creation of two-dimensional array in free store; row count should be calculated based on amount of integer values read from file and count of columns
* filling of two-dimensional array row by row; missing elements of the last row should be set to zeroes;
* removing elements of linked list from free store
* implementation of the task of Laboratory training # 4 of the course "Programming Basics (Part 1)"
* storing results in a new file
* removing both arrays using delete operators.

## Control exercise

№ 1. Create a list to represent the seasons of the year. Implement and demonstrate the overloading of ++ and -- operations.


## Commands to run
```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task1_1.cpp -o task1_1
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task1_2.cpp -o task1_2
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task1_3.cpp -o task1_3
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task1_4.cpp -o task1_4
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task1_control.cpp -o task1_control
./task1_1
./task1_2
./task1_3
./task1_4 input.txt
./task1_control
```


## Examples of program results
```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task1_1.cpp -o task1_1
./task1_1
```
![task1_1](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab1/screens/task1_1.png)

```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task1_2.cpp -o task1_2
./task1_2
```
![task1_2](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab1/screens/task1_2.png)

```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task1_3.cpp -o task1_3
./task1_3
```
![task1_3](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab1/screens/task1_3.png)

```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task1_4.cpp -o task1_4
./task1_4 input.txt
```
![task1_4](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab1/screens/task1_4.png)

![input_txt](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab1/screens/input_txt.png)

![output_txt](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab1/screens/output_txt.png)

```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task1_control.cpp -o task1_control
./task1_control
```
![task1_control](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab1/screens/task1_control.png)

© Inessa Repeshko. 2023
