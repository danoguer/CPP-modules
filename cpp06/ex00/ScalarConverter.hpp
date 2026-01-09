#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <cmath>
#include <sstream>

class ScalarConverter {
private:
    // Private constructors prevent instantiation
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

public:
    // The only way to use the class
    static void convert(const std::string& input);
};

#endif