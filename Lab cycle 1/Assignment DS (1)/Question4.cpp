#include<iostream>
#include<cstring>
using namespace std;

bool Palindrome(const string & str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return Palindrome(str, start + 1, end - 1);
}

bool PalindromeString(const string & str) {
    int length = str.length();
    return Palindrome(str, 0, length - 1);
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    if (PalindromeString(input)) {
        cout << "The string is a palindrome." <<endl;
    } else {
        cout << "The string is not a palindrome." <<endl;
    }

    return 0;
}

/*
    ****OUTPUT****

    Enter a string: SHIYAS
    The string is not a palindrome.


    Enter a string: MALAYALAM
    The string is a palindrome.

*/