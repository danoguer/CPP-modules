#include <iostream>
#include "Span.hpp"

int main()
{
    std::cout << "=== Test 1: Subject example ===" << std::endl;
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    std::cout << "\n=== Test 2: Exception - Not enough numbers ===" << std::endl;
    {
        try {
            Span sp(5);
            sp.addNumber(1);
            std::cout << sp.shortestSpan() << std::endl;
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    std::cout << "\n=== Test 3: Exception - Span full ===" << std::endl;
    {
        try {
            Span sp(2);
            sp.addNumber(1);
            sp.addNumber(2);
            sp.addNumber(3);  // Should throw
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    std::cout << "\n=== Test 4: Large test with 10000 numbers ===" << std::endl;
    {
        Span sp(10000);
        for (int i = 0; i < 10000; i++) {
            sp.addNumber(i * 2);  // Even numbers: 0, 2, 4, 6...
        }
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // Should be 2
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;    // 19998 - 0 = 19998
    }

    return 0;
}