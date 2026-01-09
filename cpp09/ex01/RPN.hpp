#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <stdexcept>
#include <cctype>
class RPN {
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    int calculate(const std::string& expression);
private:
    std::stack<int> values;
    bool isOperator(char c) const;
    int applyOperator(int a, int b, char op) const;
};

#endif
