#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

void processInputFile(const std::string& inputFile, BitcoinExchange& exchange) {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    bool firstLine = true;
    while (std::getline(file, line)) {
        if (firstLine) {
            firstLine = false;
            continue;
        }
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, pipePos);
        std::string valueStr = line.substr(pipePos + 1);
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));
        valueStr.erase(valueStr.find_last_not_of(" \t") + 1);
        try {
            std::stringstream ss(valueStr);
            double value;
            ss >> value;
            if (ss.fail()) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            if (value < 0) {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }
            if (value > 1000) {
                std::cerr << "Error: too large a number." << std::endl;
                continue;
            }
            double rate = exchange.getExchangeRate(date);
            double result = value * rate;
            std::cout << date << " => " << value << " = " << result << std::endl;

        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    file.close();
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    try {
        BitcoinExchange exchange;
        exchange.loadData("data.csv");
        processInputFile(argv[1], exchange);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
