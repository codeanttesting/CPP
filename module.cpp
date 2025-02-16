/* module.cpp */
/* Example module that intentionally violates MISRA C++ 2013 guidelines */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;  // MISRA violation: using-directive in global scope

// Forward declaration of a function from utils.cpp
extern char* utilFunction(const char* str);

// Global variable (non-const, global namespace) – MISRA violation
int globalCounter = 0;

int moduleFunction(int param)
{
    int localVar = 0;
    int i;

    // Using magic numbers directly
    if (param > 5)
        localVar = param * 7;  // Magic number 7
    else
        localVar = param + 3;  // Magic number 3

    // Unsafe use of strcpy on a fixed-size array
    char buffer[20];
    strcpy(buffer, "This string is too long for buffer");  // Risky copy

    cout << "Buffer: " << buffer << endl;

    // Unbraced if-else statement
    if (param == 10)
        cout << "Parameter is 10" << endl;
    else
        cout << "Parameter is not 10" << endl;

    // Call utility function from utils.cpp
    char* returnedString = utilFunction("Module call");
    cout << "Util function returned: " << returnedString << endl;

    // Modify global variable without protection
    globalCounter++;
    for (i = 0; i < param; i++) {
        localVar += i;
    }

    // Additional filler loop
    for (i = 0; i < 10; i++) {
        cout << "Filler loop iteration " << i << endl;
    }

    // Another magic number usage
    localVar += 42;

    if (localVar > 100)
    {
        cout << "Local variable is greater than 100" << endl;
    }
    else
    {
        cout << "Local variable is not greater than 100" << endl;
    }

    // More filler loops (unbraced single-statement loop)
    for (i = 0; i < 5; i++)
        cout << "Additional filler: " << i << endl;

    return localVar;
}

void extraModule()
{
    for (int i = 0; i < 15; i++) {
        cout << "Extra module filler: " << i << endl;
    }
}

int dummyModule(int x)
{
    return x - 1;
}

void moduleExtraLines()
{
    for (int i = 0; i < 10; i++) {
        cout << "Module extra line: " << i << endl;
    }
}

void moduleFinalFiller()
{
    for (int i = 0; i < 10; i++) {
        cout << "Module final filler: " << i << endl;
    }
}

// Additional filler to exceed 50 lines
void moduleMoreFiller()
{
    for (int i = 0; i < 20; i++) {
        cout << "Module more filler: " << i << endl;
    }
}
