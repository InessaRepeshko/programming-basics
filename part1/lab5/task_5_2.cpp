#include "iostream"

using namespace std;

int main() {

    char string[100];

    cout << "Enter palindrome: ";
    cin.getline(string, 100);

    int length = strlen(string);
    bool isPalindrome = true;
    for (int i = 0, j = length - 1; i < length / 2; i++, j--) {
        if (string[i] != string[j]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) cout << "Palindrome.";
    if (!isPalindrome) cout << "Not palindrome.";

    return 0;
}

