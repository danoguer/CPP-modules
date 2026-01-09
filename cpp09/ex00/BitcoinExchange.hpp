#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    void loadData(const std::string& filename);
    double getExchangeRate(const std::string& date) const;
private:
    std::map<std::string, double> exchangeRates;    
    bool isValidDate(const std::string& date) const;
    bool isLeapYear(int year) const;
    int daysInMonth(int month, int year) const;
    void parseLine(const std::string& line);
};

#endif