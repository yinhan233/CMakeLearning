#include "complex.h"
#include <iostream>

int main()
{
    complex a(1,2);
    complex b(3,4);

    std::cout << "a+b = " << a + b << std::endl;
    std::cout << "a-b = " << a - b << std::endl;
    std::cout << "a*b = " << a * b << std::endl;
    std::cout << "a/b = " << a / b << std::endl;
    return 0;
}