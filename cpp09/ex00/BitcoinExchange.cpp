#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    this->exchangeRates = other.exchangeRates;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->exchangeRates = other.exchangeRates;
    }
    return *this;
}

void BitcoinExchange::loadData(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        parseLine(line);
    }
    file.close();
}

void BitcoinExchange::parseLine(const std::string& line) {
    std::istringstream ss(line);
    std::string date;
    std::string rateStr;
    if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) {
        std::stringstream converter(rateStr);
        double rate;
        converter >> rate;
        exchangeRates[date] = rate;
    }
}

double BitcoinExchange::getExchangeRate(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = exchangeRates.find(date);
    if (it != exchangeRates.end()) {
        return it->second;
    }
    
    // Find the closest earlier date
    it = exchangeRates.lower_bound(date);
    if (it == exchangeRates.begin()) {
        throw std::runtime_error("bad input => " + date);
    }
    --it;
    return it->second;
}
bool BitcoinExchange::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int BitcoinExchange::daysInMonth(int month, int year) const {
    static const int daysPerMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysPerMonth[month - 1];
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    std::stringstream ss1(date.substr(0, 4));
    std::stringstream ss2(date.substr(5, 2));
    std::stringstream ss3(date.substr(8, 2));
    int year, month, day;
    ss1 >> year;
    ss2 >> month;
    ss3 >> day;
    if (month < 1 || month > 12) {
        return false;
    }
    int maxDays = daysInMonth(month, year);
    if (day < 1 || day > maxDays) {
        return false;
    }
    return true;
}

