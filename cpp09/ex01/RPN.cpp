#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN& other) {
    this->values = other.values;
}
RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        this->values = other.values;
    }
    return *this;
}

bool RPN::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::applyOperator(int a, int b, char op) const {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) {
                throw std::runtime_error("Error: Division by zero.");
            }
            return a / b;
        default:
            throw std::runtime_error("Error: Unknown operator.");
    }
}

int RPN::calculate(const std::string& expression) {
    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];
        if (std::isspace(c)) {
            continue;
        }
        if (std::isdigit(c)) {
            values.push(c - '0');
        } else if (isOperator(c)) {
            if (values.size() < 2) {
                throw std::runtime_error("Error: Insufficient values in expression.");
            }
            int b = values.top(); values.pop();
            int a = values.top(); values.pop();
            int result = applyOperator(a, b, c);
            values.push(result);
        } else {
            throw std::runtime_error(std::string("Error: Invalid character '") + c + "'.");
        }
    }
    if (values.size() != 1) {
        throw std::runtime_error("Error: The user input has too many values.");
    }
    return values.top();
}

