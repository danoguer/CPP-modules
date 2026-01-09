#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }
Intern::~Intern() {}

AForm* Intern::makeForm(std::string name, std::string target) {
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    int i = 0;
    while (i < 3 && formNames[i] != name) {
        i++;
    }

    AForm* result = NULL;
    switch (i) {
        case 0:
            result = new ShrubberyCreationForm(target);
            break;
        case 1:
            result = new RobotomyRequestForm(target);
            break;
        case 2:
            result = new PresidentialPardonForm(target);
            break;
        default:
            std::cout << "Error: Intern cannot create " << name << " because it doesn't exist." << std::endl;
            return NULL;
    }
    std::cout << "Intern creates " << name << std::endl;
    return result;
}