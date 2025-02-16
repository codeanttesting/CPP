/* utils.cpp */
/* Utility functions intentionally violating MISRA C++ 2013 guidelines */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;  // MISRA violation: using-directive in global scope

// Function that returns a pointer to a local variable (violation)
char* utilFunction(const char* str)
{
    char localArray[50];
    // Unsafe use of sprintf (no bounds checking)
    sprintf(localArray, "Util says: %s", str);
    cout << "Inside utilFunction: " << localArray << endl;
    
    // Returning address of a local array (lifetime issue)
    return localArray;
}

// Function that uses dynamic memory allocation unsafely
char* allocateString(const char* input)
{
    char* newString;
    // Violating MISRA by not checking the allocation result
    newString = new char[strlen(input) + 1];
    strcpy(newString, input);  // Unsafe use of strcpy
    return newString;
}

int computeValue(int a, int b)
{
    int result;
    // Implicit conversion and unsafe use of a primitive type
    unsigned int temp = a;
    result = temp + b;
    
    // Unbraced if-else statement
    if (a > b)
        result += 10;
    else
        result -= 10;

    // Use of a magic number
    result += 99;

    // Filler loop with output
    for (int i = 0; i < 20; i++) {
        cout << "Compute filler iteration " << i << ", result = " << result << endl;
    }
    return result;
}

void utilFiller()
{
    for (int i = 0; i < 10; i++) {
        cout << "Util filler line: " << i << endl;
    }
}

void utilExtra()
{
    int j = 0;
    while (j < 5)
    {
        cout << "Util extra line: " << j << endl;
        j++;
    }
}

void utilDummy()
{
    for (int k = 0; k < 10; k++) {
        cout << "Util dummy line: " << k << endl;
    }
}

void utilFinalFiller()
{
    for (int i = 0; i < 15; i++) {
        cout << "Util final filler: " << i << endl;
    }
}

// Additional filler function
void utilMoreFiller()
{
    for (int i = 0; i < 10; i++) {
        cout << "Util more filler: " << i << endl;
    }
}

// Final extra filler to exceed 50 lines
void utilFinalExtra()
{
    for (int i = 0; i < 10; i++) {
        cout << "Util final extra line: " << i << endl;
    }
}
