#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(NULL));

    Bureaucrat boss("The Boss", 1);
    Bureaucrat intern("The Intern", 150);
    Bureaucrat mid("Manager", 40);

    std::cout << "\n--- TEST 1: Shrubbery (145 sign, 137 exec) ---" << std::endl;
    ShrubberyCreationForm shrub("Garden");
    std::cout << shrub << std::endl;
    
    intern.executeForm(shrub);
    boss.signForm(shrub);
    intern.executeForm(shrub);
    boss.executeForm(shrub);

    std::cout << "\n--- TEST 2: Robotomy (72 sign, 45 exec) ---" << std::endl;
    RobotomyRequestForm rob("Bender");
    boss.signForm(rob);
    mid.executeForm(rob);
    mid.executeForm(rob);
    mid.executeForm(rob);

    std::cout << "\n--- TEST 3: Presidential Pardon (25 sign, 5 exec) ---" << std::endl;
    PresidentialPardonForm pardon("Criminal");
    mid.signForm(pardon);
    boss.signForm(pardon);
    mid.executeForm(pardon);
    boss.executeForm(pardon);

    std::cout << "\n--- TEST 4: Cleanup and Scope ---" << std::endl;
    {
        AForm* f = new PresidentialPardonForm("Prisoner");
        boss.signForm(*f);
        boss.executeForm(*f);
        delete f;
    }

    return 0;
}