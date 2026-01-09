#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    {
        try {
            Form f1("Top Secret", 0, 50);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        try {
            Form f2("Garbage", 151, 50);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "-----------------------" << std::endl;

    {
        try {
            Bureaucrat b1("Boss", 1);
            Form f1("Presidential Pardon", 5, 1);
            
            std::cout << b1 << std::endl;
            std::cout << f1 << std::endl;
            
            b1.signForm(f1);
            std::cout << f1 << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "-----------------------" << std::endl;

    {
        try {
            Bureaucrat b2("Intern", 150);
            Form f2("Presidential Pardon", 5, 1);
            
            std::cout << b2 << std::endl;
            std::cout << f2 << std::endl;
            
            b2.signForm(f2);
            std::cout << f2 << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}