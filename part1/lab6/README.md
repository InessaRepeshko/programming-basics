## Laboratory Training № 6 "Pointers to Functions and Header Files"

## 6.1 Output of the Table of Values of Function
Create a separate translation unit in which you should implement the function of outputting a table of values of a certain function with a certain step. Function parameters are: the beginning, end of the interval, step and pointer to the function, the values of which will be displayed in the table. In the header file, you must declare the type of function pointer and the prototype of the value table output function. In the implementation file, define the value table output function.

In another translation unit, you should place the functions for which you want to output values in a table, as well as the main () function, which outputs tables of values to at least two different functions. One of the functions for testing is a function determined from the task of the first laboratory training and implemented in the third laboratory training.

## 6.2 Individual Assignment
Write a program that implements exhaustive search of some value according to an individual assignment. Necessary value can be found by testing intermediate values of a function. Use typedefs and pointers to functions.

The source code should be split into two translation units. The first translation unit will be represented by both header file and implementation file. The typedef definition, as well as declaration of function that searches necessary value, should be placed into header file. The definition of this function will take place in implementation file corresponding to header file. The testing function, as well as main() function, should be placed into another translation unit.

The task requirement of variant 25:

![var25](https://github.com/InessaRepeshko/programming-basics/blob/main/part1/lab6/screens/var25.png)

You should check the functionality of the program on at least two arbitrary functions. One of the functions can be standard.

Note: To calculate first derivative of y(x), you can use the following formula:

*y'(x) = (y(x + Δx) - y(x)) / Δx,*

Where Δx is some tiny value, such as 0.0000001.


## Commands to run
```
For task6_1:
g++ Header.h Header.cpp Task.cpp
./a.out

For task6_2:
g++ Header.h Header.cpp Task.cpp
./a.out
```


## Examples of program results
```
Task6_1:
g++ Header.h Header.cpp Task.cpp
./a.out
```
![task6_1](https://github.com/InessaRepeshko/programming-basics/blob/main/part1/lab6/screens/task6_1.png)

```
Task6_2:
g++ Header.h Header.cpp Task.cpp
./a.out
```
![task6_2](https://github.com/InessaRepeshko/programming-basics/blob/main/part1/lab6/screens/task6_2.png)

© Inessa Repeshko. 2022
