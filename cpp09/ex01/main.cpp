#include "RPN.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Too many arguments" << std::endl;
        return 1;
    }
    RPN rpnCalculator;
    try {
        int result = rpnCalculator.calculate(argv[1]);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
    
}