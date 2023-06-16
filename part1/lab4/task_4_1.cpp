#include <iostream>
using namespace std;

void printBinary(unsigned short int n)
{
    int binaryNum[16];

    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}

int main()
{
    unsigned short int n;

    std::cout << "Integer: ";
    std::cin >> n;
    printBinary(n);

    return 0;
}
