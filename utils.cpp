#include <iostream>
#include <memory>   // For std::unique_ptr and std::auto_ptr
#include <cstdlib>

#pragma message("Compiling module3.cpp") // Violation: The #pragma directive shall not be used.

// Violation: Using an undefined macro identifier in a preprocessor directive.
#if UNDEFINED_MACRO
#error "Undefined macro used in preprocessor condition"
#endif

// Violation: Function-like macro whose argument contains tokens resembling preprocessor directives.
#define BAD_MACRO(arg) (arg)
#define PREPROCESS_MACRO(x) BAD_MACRO( "#define " #x )

// Violation: The std::auto_ptr shall not be used.
std::auto_ptr<int> autoPtr(new int(10));

class TemplateClass {
public:
    // Violation: Template constructor with a single generic parameter is defined without a copy constructor.
    template<typename T>
    TemplateClass(T value) {
        std::cout << "TemplateClass constructed with value: " << value << std::endl;
    }
};

// Violation: The std::unique_ptr shall not be passed by const reference.
void useUniquePtr(const std::unique_ptr<int>& uptr) {
    std::cout << "Unique pointer value: " << *uptr << std::endl;
}

int main() {
    std::cout << PREPROCESS_MACRO(test) << std::endl; // Invocation of a problematic macro.
    TemplateClass obj(42);
    std::unique_ptr<int> uniquePtr(new int(5));
    useUniquePtr(uniquePtr);

    return 0;
}