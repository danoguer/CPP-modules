
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { *this = other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& input) {
    std::string charOutput = "";
    std::string intOutput = "";
    std::string floatOutput = "";
    std::string doubleOutput = "";

    if (input == "nan" || input == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    } else if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
        return;
    } else if (input == "-inf" || input == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }

    char* end;
    double dblVal = std::strtod(input.c_str(), &end);

    if (input.length() == 1 && !std::isdigit(input[0])) {
        dblVal = static_cast<double>(input[0]);
    } 
    else if (*end != '\0' && (*end != 'f' || *(end + 1) != '\0')) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    if (dblVal < CHAR_MIN || dblVal > CHAR_MAX || std::isnan(dblVal)) {
        charOutput = "impossible";
    } else if (!std::isprint(static_cast<char>(dblVal))) {
        charOutput = "Non displayable";
    } else {
        charOutput = "'";
        charOutput += static_cast<char>(dblVal);
        charOutput += "'";
    }

    if (dblVal < INT_MIN || dblVal > INT_MAX || std::isnan(dblVal)) {
        intOutput = "impossible";
    } else {
        std::stringstream ss;
        ss << static_cast<int>(dblVal);
        intOutput = ss.str();
    }

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "char: " << charOutput << std::endl;
    std::cout << "int: " << intOutput << std::endl;
    std::cout << "float: " << static_cast<float>(dblVal) << "f" << std::endl;
    std::cout << "double: " << dblVal << std::endl;
}
    