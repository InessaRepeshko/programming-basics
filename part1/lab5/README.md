## Laboratory Training № 5 "Working with Pointers, Strings, and Files"

## 5.1 Sum of the Minimum and Maximum Items

Write a program that calculates the sum of the minimum and maximum items of an array of double precision floating point values. Use two separate functions. The program must meet the following requirements:
* the array length should be read from the keyboard using the scanf() function;
* the array is created in free store;
* the array should be filled with random values in the range from 0 to 100;
* the array should be bypassed using address arithmetic;
* the parameters of the function of calculating the minimum and maximum items are the pointers to double and the array size;
* the result should be shown using printf() function;
* data must be deallocated from the free store.

## 5.2 Checking Palindromes

Read a sentence (array of characters) from the keyboard using the getline() function, check whether it is a palindrome and display the corresponding message. Recommendation: do not use capital letters when entering. The result should be displayed using printf() function.

A palindrome is a sentence that reads the same in both directions (from left to right and from right to left), for example, "never odd or even" Spaces and punctuation are not taken into account. In the software implementation, it is advisable to remove them and check the resulting string.

## 5.3 Individual Assignment
Prepare a text file that contains information about the size of the two-dimensional array, determined in the individual task of the previous laboratory training. Sizes must be represented by two integers separated space character. On the following rows place the array items linewise.

The program should contain the following activities:
* creation of a two-dimensional array of integer items in free store by reading its sizes from the file;
* reading array items from file;
* creation of a second array of required size in free store;
* processing the first array and fill the second array according to the individual task of the previous laboratory training;
* creation of a text file and write the modified first array items in it;
* creation of another text file and write the items of the second array in it;
* deallocation arrays from free store.

In parallel with the output to the file, you should provide output to the console window using the printf() function. When working with a one-dimensional array, use an address arithmetic instead of working with the index is required.

The task requirement of variant 25:
![var25](https://github.com/InessaRepeshko/programming-basics/blob/main/part1/lab4/screens/var25.png)


## Commands to run
```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task5_1.cpp -o task5_1
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task5_2.cpp -o task5_2
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task5_3.cpp -o task5_3
./task5_1
./task5_2
./task5_3
```


## Examples of program results
```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task5_1.cpp -o task5_1
./task5_1
```
![task5_1](https://github.com/InessaRepeshko/programming-basics/blob/main/part1/lab5/screens/task5_1.png)

```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task5_2.cpp -o task5_2
./task5_2
```
![task5_2](https://github.com/InessaRepeshko/programming-basics/blob/main/part1/lab5/screens/task5_2.png)

```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task5_3.cpp -o task5_3
./task5_3
```
![task5_3](https://github.com/InessaRepeshko/programming-basics/blob/main/part1/lab5/screens/task5_3.png)

© Inessa Repeshko. 2022
