/* main.cpp */
/* Example program that intentionally violates MISRA C++ 2013 guidelines */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;  // MISRA violation: using-directive in global scope

// Forward declaration of a function from module.cpp
extern int moduleFunction(int param);

void filler1() {
    for (int i = 0; i < 10; i++) {
        cout << "Filler1 line: " << i << endl;
    }
}

void filler2() {
    int i = 0;
    while (i < 10) {
        cout << "Filler2 line: " << i << endl;
        i++;
    }
}

int main() {
    char input[100];
    cout << "Enter a string: ";
    gets(input);  // MISRA violation: using gets (unsafe C library function)

    int uninit;  // Uninitialized variable (violation)
    cout << "Uninitialized variable value: " << uninit << endl;  // Using uninitialized value

    int result = moduleFunction(5);
    cout << "Module function returned: " << result << endl;

    char* ptr = input;
    if (*ptr == 'a')
        cout << "String starts with a" << endl;
    else
        cout << "String does not start with a" << endl;

    result = moduleFunction(10);
    cout << "Module function returned: " << result << endl;

    for (int i = 0; i < 3; i++)
        cout << "Loop iteration " << i << ": " << input << endl;

    // Additional filler code to increase file length
    for (int i = 0; i < 20; i++) {
        cout << "Additional filler line " << i << endl;
    }

    filler1();
    filler2();

    for (int i = 0; i < 15; i++) {
        cout << "Extra filler " << i << endl;
    }

    // Dummy operation using the uninitialized variable
    int dummyResult = uninit + result;
    cout << "Dummy result: " << dummyResult << endl;

    for (int i = 0; i < 10; i++) {
        cout << "Final filler line " << i << endl;
    }

    return 0;
}
