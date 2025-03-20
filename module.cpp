#include <iostream>
#include <cstdlib> // Violation: Use of atoi from <cstdlib> is disallowed by AUTOSAR.

// Violation: In a namespace, the identifier of a static function shall not be reused.
namespace MyNamespace {
    static void helper() {
        std::cout << "Helper function version 1" << std::endl;
    }
    static void helper() { // duplicate static function name
        std::cout << "Helper function version 2" << std::endl;
    }
}

// Violation: Objects with external linkage should be declared in a header file.
int globalData = 100;

class Base {
public:
    // Violation: Virtual function with default parameter.
    virtual void process(int x = 10) {
        std::cout << "Base processing: " << x << std::endl;
    }
};

class Derived : public Base {
public:
    // Violation: Overriding virtual function with different default argument.
    virtual void process(int x = 20) {
        std::cout << "Derived processing: " << x << std::endl;
    }
};

void misusePointer() {
    // Violation: The address of an object with automatic storage shall not be assigned to an object
    // that may persist after the original object ceases to exist.
    int localVar = 5;
    static int* globalPtr = nullptr;
    globalPtr = &localVar;  // local address assigned to a static variable
}

void pointerConversion() {
    class VirtualBase { public: virtual ~VirtualBase() {} };
    class VirtualDerived : public VirtualBase {};
    VirtualBase* vb = new VirtualDerived();
    // Violation: Pointer conversion from a virtual base class using static_cast instead of dynamic_cast.
    VirtualDerived* vd = static_cast<VirtualDerived*>(vb);
    delete vb;
}

// Violation: Enumerations shall be declared as scoped enum classes.
enum Color { RED, GREEN, BLUE };

void outerFunction() {
    // Violation: Function declared at block scope.
    void innerFunction() {
        std::cout << "Inside inner function" << std::endl;
    }
    innerFunction();
}

int main() {
    MyNamespace::helper(); // Which version is called is ambiguous.
    Base* baseObj = new Base();
    baseObj->process(); // Uses Base default argument.
    Derived* derivedObj = new Derived();
    derivedObj->process(); // Uses different default argument.
    delete baseObj;
    delete derivedObj;

    misusePointer();
    pointerConversion();
    outerFunction();

    // Violation: Use of atoi is forbidden.
    int num = atoi("123");

    return 0;
}
