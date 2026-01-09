
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() 
    :   _name("Default"), 
        _isSigned(false),
        _gradeToSign(150), 
        _gradeToExec(150) {  
}

AForm::~AForm() { }

AForm::AForm(const AForm &other) 
    :   _name(other._name), 
        _isSigned(other._isSigned),
        _gradeToSign(other._gradeToSign), 
        _gradeToExec(other._gradeToExec) {
}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other)
        this->_isSigned = other._isSigned;
    return *this;
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExec) 
    :   _name(name),
        _isSigned(false), 
        _gradeToSign(gradeToSign),
        _gradeToExec(gradeToExec) { 
    if (gradeToSign < 1 || gradeToExec < 1)
            throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
            throw AForm::GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() <= this->_gradeToSign) {
        this->_isSigned = true;
    } else {
        throw AForm::GradeTooLowException();
    }
}

std::string AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExec() const { return _gradeToExec; }

const char* AForm::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed yet!";
}

std::ostream &operator<<(std::ostream &o, const AForm &f) {
    o << "AForm " << f.getName() << " (sign grade " << f.getGradeToSign() 
      << ", exec grade " << f.getGradeToExec() << ") Status: " 
      << (f.getIsSigned() ? "signed" : "not signed");
    return o;
}
