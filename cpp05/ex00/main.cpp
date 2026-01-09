
#include "Bureaucrat.hpp"

int main() {
    std::cout << "--- Test 1: Valid Bureaucrat ---" << std::endl;
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Grade Too High (0) ---" << std::endl;
    try {
        Bureaucrat boss("The Boss", 0);
    } catch (std::exception &e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Grade Too Low (151) ---" << std::endl;
    try {
        Bureaucrat intern("Intern", 151);
    } catch (std::exception &e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }
    std::cout << "\n--- Test 4: Incrementing Grade 1 ---" << std::endl;
    try {
        Bureaucrat hermes("Hermes", 1);
        std::cout << hermes << std::endl;
        hermes.incrementGrade();
    } catch (std::exception &e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 5: Decrementing Grade 150 ---" << std::endl;
    try {
        Bureaucrat low("Low Level", 150);
        std::cout << low << std::endl;
        low.decrementGrade();
    } catch (std::exception &e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }
    return 0;
}