#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("ShrubberyCreationForm", 145, 137), _target("default") {}


ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
    : AForm(other), _target(other._target) {}


ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExec()) {
        throw AForm::GradeTooLowException();
    }

    std::string fileName = _target + "_shrubbery";
    std::ofstream outfile(fileName.c_str());

    if (!outfile.is_open()) {
        std::cerr << "Error: Could not create file " << fileName << std::endl;
        return;
    }

    outfile << "               ,@@@@@@@," << std::endl;
    outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
    outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
    outfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
    outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
    outfile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
    outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
    outfile << "       |o|        | |         | |" << std::endl;
    outfile << "       |.|        | |         | |" << std::endl;
    outfile << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;

    outfile.close();
    std::cout << "Shrubbery has been planted at " << fileName << std::endl;
}