#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <stdexcept>
#include <ctime>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

    void parseInput(int argc, char** argv);
    void sortAndMeasure();
private:
    std::vector<int> vecData;
    std::deque<int> deqData;
    void mergeInsertSort(std::vector<int>& data);
    void mergeInsertSort(std::deque<int>& data);
    void binaryInsert(std::vector<int>& data, int value, size_t end);
    void binaryInsert(std::deque<int>& data, int value, size_t end);
    size_t generateJacobsthal(size_t n);
    std::vector<size_t> createInsertionOrder(size_t pendSize);
    void printData(const std::vector<int>& data);
    void printData(const std::deque<int>& data);
    bool isSorted(const std::vector<int>& data);
    bool isSorted(const std::deque<int>& data);
    void validateInput(const std::string& str);
};

#endif