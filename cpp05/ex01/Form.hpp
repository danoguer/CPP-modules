
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form {
private :
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExec;
public:
    Form();
    ~Form();
    Form(const Form &other);
    Form &operator=(const Form &other);
    Form(const std::string name, int gradeToSign, int GradeToExec);

    bool getIsSigned() const;
    std::string getName() const;
    int getGradeToSign() const;
    int getGradeToExec() const;
    void beSigned(const Bureaucrat &b);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &o, const Form &f);

#endif