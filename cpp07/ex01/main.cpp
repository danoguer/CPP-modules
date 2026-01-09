#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(T const & x) {
    std::cout << x << " ";
}

template <typename T>
void incrementElement(T const & x) {
    std::cout << x + 1 << " ";
}

void toUpper(char const & c) {
    std::cout << static_cast<char>(toupper(c));
}

int main(void) {
    std::cout << "=== Test 1: Array of integers ===" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = 5;
    
    std::cout << "Print: ";
    iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;
    
    std::cout << "Increment: ";
    iter(intArray, intLen, incrementElement<int>);
    std::cout << std::endl;

    std::cout << "\n=== Test 2: Array of floats ===" << std::endl;
    float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f};
    size_t floatLen = 4;
    
    std::cout << "Print: ";
    iter(floatArray, floatLen, printElement<float>);
    std::cout << std::endl;

    std::cout << "\n=== Test 3: Array of strings ===" << std::endl;
    std::string strArray[] = {"Hello", "World", "42", "School"};
    size_t strLen = 4;
    
    std::cout << "Print: ";
    iter(strArray, strLen, printElement<std::string>);
    std::cout << std::endl;

    std::cout << "\n=== Test 4: Array of chars ===" << std::endl;
    char charArray[] = {'h', 'e', 'l', 'l', 'o'};
    size_t charLen = 5;
    
    std::cout << "Original: ";
    iter(charArray, charLen, printElement<char>);
    std::cout << std::endl;
    
    std::cout << "Uppercase: ";
    iter(charArray, charLen, toUpper);
    std::cout << std::endl;

    return 0;
}