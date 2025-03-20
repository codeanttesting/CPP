// Violation: Code appears before include directives.
int dummyGlobal = 0;

#include <iostream>
#include <cstring>

// Violation: Global variable with external linkage not declared in a header.
int globalVar = 0;

int main() {
    // Violation: Sections of code shall not be commented out.
    // int unused = 100;

    // Violation: Use of octal constant (other than 0).
    int octalValue = 0123;

    // Violation: String literals with different encoding prefixes shall not be concatenated.
    auto str = u8"Hello, " L"World!";

    // Violation: Literal zero (0) used as the null-pointer constant.
    int* ptr = 0;

    // Violation: Function declared at block scope.
    void blockFunction() {
        std::cout << "Inside block function" << std::endl;
    }
    blockFunction();

    // Violation: Overlapping object assignment.
    char buffer[20];
    std::strcpy(buffer, "Overlapping copy");
    std::memcpy(buffer + 5, buffer, 10); // overlapping copy

    // Violation: Pointer subtraction applied to pointers from different arrays.
    int array1[5] = {1, 2, 3, 4, 5};
    int array2[5] = {5, 4, 3, 2, 1};
    int diff = (&array1[2] - &array2[2]); // undefined behavior

    // Violation: Lambda expression used in the same scope should capture by reference
    // and its non-void return type should be explicitly specified.
    int x = 10;
    auto lambda = [x]() { return x + 1; };
    std::cout << "Lambda result: " << lambda() << std::endl;

    // Violation: Increment operator mixed with other operators.
    int i = 0;
    int mixed = i++ + 5;

    // Violation: Use of dynamic_cast (should not be used).
    class Base { public: virtual ~Base() {} };
    class Derived : public Base {};
    Base* b = new Derived();
    Derived* d = dynamic_cast<Derived*>(b);
    delete b;

    // Violation: Use of reinterpret_cast (shall not be used).
    long addr = reinterpret_cast<long>(ptr);

    // Violation: Overloading the unary '&' operator.
    class Overloaded {
    public:
        int value;
        Overloaded(int v) : value(v) {}
        int operator&() { return value; }
    };
    Overloaded obj(42);
    std::cout << "Overloaded operator& result: " << &obj << std::endl;

    return 0;
}
