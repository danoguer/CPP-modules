#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
    std::srand(std::time(NULL));

    std::cout << "--- Testing Exercise 02: Identify Real Type ---" << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << "\nTest #" << i + 1 << ":" << std::endl;
        Base* instance = generate();
        std::cout << "Identification by pointer:   ";
        identify(instance);
        std::cout << "Identification by reference: ";
        identify(*instance);
        delete instance;
    }

    std::cout << "\n--------------------------------------------" << std::endl;

    return 0;
}