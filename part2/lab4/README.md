## Laboratory Training № 4 "Use of the Standard Template Library"

## 4.1 Presentation and Processing of Data about Students using the Standard Template Library

Complete task 1.3 of the second laboratory training (Classes for Representing Students and Groups).

In the "Student" class, use a std::string of type to store the last name. Store grades for the last session in a vector of integers std::vector<int>). In addition to the functions listed in task 1.3 of the second laboratory training, you should implement functions that perform:
* calculating the value that is used for sorting according to individual task;
* test conditions used for searching data according to individual task.

In the "Group of students" class, place a vector of objects that represents a student. Implement the functions defined in task 1.3 of the second laboratory training for this class. To sort the array according to the criteria specified in the individual task, use the sort() algorithm. To find data about students that meet the condition given in the individual task, apply the for_each() algorithm.

Additionally, place objects of" "Student" class into priority queue and obtain objects in descending order of the average score.

## 4.2 The Vector of Vectors for Representation of Two-Dimensional Array

Complete task 1.4 of the second laboratory training (Class for Representing a Two-Dimensional Array) by creating a class whose field is a vector of vectors of the Standard template library. The created class does not require a copy constructor, destructor and overloaded assignment operator, because data is not placed into free store (vectors are responsible for this).

## 4.3 Counting the Number of Repetitions of Values (Additional Task)

Develop a program in which integer values are read and the number of repetitions of each value is counted, except for the numbers given in some list. Counting the repetitions of a number should be implemented using map, the list of numbers for exclusion should be implemented using a set. Each time a number from the list is encountered, output message.

## Control exercise

№ 2. Enter information about the students of the group into the multimap container. The key is the surname, the group can have namesakes. Give a message if the group has namesake. Provide data about the students of the group by alphabet of names.


## Commands to run
```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task4_1.cpp -o task4_1
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task4_2.cpp -o task4_2
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task4_3.cpp -o task4_3
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task4_control.cpp -o task4_control
./task4_1
./task4_2
./task4_3
./task4_control
```


## Examples of program results
```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task4_1.cpp -o task4_1
./task4_1
```
![task4_1](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab4/screens/task4_1.png)

```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task4_2.cpp -o task4_2
./task4_2
```
![task4_2](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab4/screens/task4_2.png)

```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task4_3.cpp -o task4_3
./task4_3
```
![task4_3](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab4/screens/task4_3.png)

![data_txt](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab4/screens/data_txt.png)

```
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task4_control.cpp -o task4_control
./task4_control
```
![task4_control](https://github.com/InessaRepeshko/programming-basics/blob/main/part2/lab4/screens/task4_control.png)

© Inessa Repeshko. 2023
