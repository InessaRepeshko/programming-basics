## Laboratory Training № 2 "C++ Operators and Statements".

## 2.1 Programmatic Implementation of Branching Algorithm
Develop a program that implements an algorithm for solving quadratic equation. The program should include checking all possible variants of the source data. In particular, the discriminant should be checked, and it should be checked whether the equation is quadratic. If the equation degenerates into a linear one, it is necessary to provide for finding the root of this linear equation, or to establish the presence of infinite count of solutions (absence of solutions).

## 2.2 Programmatic Implementation of Looping Algorithm

Develop a program that implements an algorithm for calculating the following expression:

y = 1/(x + 2) + 2/(x + 4) + ... + (k - 1)/(x + 2(k - 1)) + (k + 1)/(x + 2(k + 1)) + ... + n/(x + 2n)

Provide a check of possible errors.

## 2.3 Calculating Product

Write a program that reads x and n and calculates y:

y = (x + 1)(x - 2)(x + 3)(x - 4) ... (x - 2n)

## 2.4 Calculating Product

Write a program that reads eps and calculates y:

y = 1/2 + 1/4 + 1/8 + 1/16 + ...

The loop terminates if new summand is less than eps.

## 2.5 Individual Assignment

You should develop a program that calculates values of a function in a given range. The program should implement an algorithm developed in carrying out assignment 1.3 of previous lab.
![Function_var18](https://github.com/InessaRepeshko/programming-basics/blob/main/part1/lab1/screens/Function_var18.png)


## Commands to run
```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_1.cpp -o task2_1
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_2.cpp -o task2_2
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_3.cpp -o task2_3
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_4.cpp -o task2_4
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_5.cpp -o task2_5
./task2_1
./task2_2
./task2_3
./task2_4
./task2_5
```


## Examples of program results
```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_1.cpp -o task2_1
./task2_1
```
![task2_1](https://github.com/InessaRepeshko/programming-basics/blob/main/part1/lab2/screens/task2_1.png)

```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_2.cpp -o task2_2
./task2_2
```
![task2_2](https://github.com/InessaRepeshko/programming-basics/blob/main/part1/lab2/screens/task2_2.png)

```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_3.cpp -o task2_3
./task2_3
```
![task2_3](https://github.com/InessaRepeshko/programming-basics/blob/main/part1/lab2/screens/task2_3.png)

```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_4.cpp -o task2_4
./task2_4
```
![task2_4](https://github.com/InessaRepeshko/programming-basics/blob/main/part1/lab2/screens/task2_4.png)

```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_5.cpp -o task2_5
./task2_5
```
![task2_5](https://github.com/InessaRepeshko/programming-basics/blob/main/part1/lab2/screens/task2_5.png)

© Inessa Repeshko. 2022
