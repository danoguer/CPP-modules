
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) 
    : _name(other._name), _grade(other._grade) {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other)
        this->_grade = other._grade;
    return *this;
}

std::string Bureaucrat::getName() const { return this->_name; }

int Bureaucrat::getGrade() const { return this->_grade; }

void Bureaucrat::incrementGrade() {
    if (_grade == 1) throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade == 150) throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b) {
    o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return o;
}



