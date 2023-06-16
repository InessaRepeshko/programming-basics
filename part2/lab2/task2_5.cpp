/* 2.5 Підрахунок суми введених значень
 * Створити клас з одним закритим елементом даних цілого типу, геттером і конструктором з одним параметром.
 * В цьому ж класі створити закрите статичне поле,
 * яке зберігає суму цілих елементів даних всіх раніше створених об'єктів.
 * Під час кожного виклику конструктора до статичного поля повинно додаватися нове значення.
 * Статична публічна функція цього ж класу повинна повертати цю суму.
 * У функції main() створити декілька об'єктів і вивести отриману суму. */

/* Commands to run:
g++ -std=c++11 -Wall -Wextra -Werror -Wpedantic task2_5.cpp -o task2_5
./task2_5
*/

//Calculating the sum of the entered values
#include <iostream>

//Class for the calculation of the sum of the entered values
class SumOfElements {
private:
    int data;
    static int sum_of_elements; //Static variable for storing the sum of elements
public:
    //Constructor with 1 parameter
    SumOfElements(int data) : data(data) { sum_of_elements += data;}
    int getData() const { return data; }
    //Static method for getting the sum_of_elements
    static int sumOfElements() { return sum_of_elements; }
};

//Initialising the static variable sum_of_elements
int SumOfElements::sum_of_elements = 0;

int main() {
    SumOfElements elem1(200);
    SumOfElements elem2(-200);
    SumOfElements elem3(90);
    SumOfElements elem4(89);
    SumOfElements elem5(-91);
    SumOfElements elem6(7);
    SumOfElements elem7(8);
    SumOfElements elem8(1000);

    std::cout << "Sum of all elements = " << SumOfElements::sumOfElements() << std::endl;
    return 0;
}
