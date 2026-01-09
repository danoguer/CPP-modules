#include "PmergeMe.hpp"
#include <climits>
#include <cstdlib>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) : vecData(other.vecData), deqData(other.deqData) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        vecData = other.vecData;
        deqData = other.deqData;
    }
    return *this;
}

void PmergeMe::validateInput(const std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            throw std::invalid_argument("Error: Non-integer input detected.");
        }
    }
    char* endptr;
    long num = std::strtol(str.c_str(), &endptr, 10);
    if (num < 0 || num > INT_MAX) {
        throw std::out_of_range("Error: Integer out of range.");
    }
}

void PmergeMe::parseInput(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        validateInput(arg);
        int num = std::atoi(arg.c_str());
        vecData.push_back(num);
        deqData.push_back(num);
    }
}

void PmergeMe::binaryInsert(std::vector<int>& data, int value, size_t end) {
    if (end == 0) {
        data.insert(data.begin(), value);
        return;
    }
    size_t left = 0;
    size_t right = end;
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (data[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    data.insert(data.begin() + left, value);
}

void PmergeMe::binaryInsert(std::deque<int>& data, int value, size_t end) {
    if (end == 0) {
        data.insert(data.begin(), value);
        return;
    }
    size_t left = 0;
    size_t right = end;
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (data[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    data.insert(data.begin() + left, value);
}

size_t PmergeMe::generateJacobsthal(size_t n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    size_t prev = 0;
    size_t curr = 1;
    for (size_t i = 2; i <= n; ++i) {
        size_t next = curr + 2 * prev;
        prev = curr;
        curr = next;
    }
    return curr;
}

std::vector<size_t> PmergeMe::createInsertionOrder(size_t pendSize) {
    if (pendSize == 0) return std::vector<size_t>();
    std::vector<size_t> insertionOrder;
    std::vector<bool> inserted(pendSize, false);
    insertionOrder.push_back(0);
    inserted[0] = true;
    std::vector<size_t> jacobsthal;
    size_t index = 1;
    while (true) {
        size_t jac = generateJacobsthal(index);
        if (jac >= pendSize) break;
        jacobsthal.push_back(jac);
        index++;
    }
    size_t prevJac = 0;
    for (size_t i = 0; i < jacobsthal.size(); ++i) {
        size_t currentJac = jacobsthal[i];
        for (size_t j = currentJac; j > prevJac && j < pendSize; --j) {
            if (!inserted[j]) {
                insertionOrder.push_back(j);
                inserted[j] = true;
            }
        }
        prevJac = currentJac;
    }
    for (size_t i = 1; i < pendSize; ++i) {
        if (!inserted[i]) {
            insertionOrder.push_back(i);
        }
    }
    return insertionOrder;
}

void PmergeMe::mergeInsertSort(std::vector<int>& data) {
    size_t n = data.size();
    if (n <= 1) return;
    if (n <= 5) {
        for (size_t i = 1; i < n; ++i) {
            int key = data[i];
            int j = i - 1;
            while (j >= 0 && data[j] > key) {
                data[j + 1] = data[j];
                --j;
            }
            data[j + 1] = key;
        }
        return;
    }
    std::vector<std::pair<int, int> > pairs;
    bool hasStraggler = (n % 2 != 0);
    int straggler = hasStraggler ? data[n - 1] : 0;
    for (size_t i = 0; i + 1 < n; i += 2) {
        if (data[i] > data[i + 1]) {
            pairs.push_back(std::make_pair(data[i], data[i + 1]));
        } else {
            pairs.push_back(std::make_pair(data[i + 1], data[i]));
        }
    }
    std::vector<int> mainChain;
    std::vector<int> pend;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }
    mergeInsertSort(mainChain);
    std::vector<int> result;
    if (!pend.empty()) {
        result.push_back(pend[0]);
    }
    for (size_t i = 0; i < mainChain.size(); ++i) {
        result.push_back(mainChain[i]);
    }
    std::vector<size_t> insertionOrder = createInsertionOrder(pend.size());
    for (size_t i = 1; i < insertionOrder.size(); ++i) {
        size_t pendIndex = insertionOrder[i];
        binaryInsert(result, pend[pendIndex], result.size());
    }
    if (hasStraggler) {
        binaryInsert(result, straggler, result.size());
    }
    data = result;
}

void PmergeMe::mergeInsertSort(std::deque<int>& data) {
    size_t n = data.size();
    if (n <= 1) return;
    if (n <= 5) {
        for (size_t i = 1; i < n; ++i) {
            int key = data[i];
            int j = i - 1;
            while (j >= 0 && data[j] > key) {
                data[j + 1] = data[j];
                --j;
            }
            data[j + 1] = key;
        }
        return;
    }
    std::vector<std::pair<int, int> > pairs;
    bool hasStraggler = (n % 2 != 0);
    int straggler = hasStraggler ? data[n - 1] : 0;
    for (size_t i = 0; i + 1 < n; i += 2) {
        if (data[i] > data[i + 1]) {
            pairs.push_back(std::make_pair(data[i], data[i + 1]));
        } else {
            pairs.push_back(std::make_pair(data[i + 1], data[i]));
        }
    }
    std::deque<int> mainChain;
    std::deque<int> pend;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }
    mergeInsertSort(mainChain);
    std::deque<int> result;
    if (!pend.empty()) {
        result.push_back(pend[0]);
    }
    for (size_t i = 0; i < mainChain.size(); ++i) {
        result.push_back(mainChain[i]);
    }
    std::vector<size_t> insertionOrder = createInsertionOrder(pend.size());
    for (size_t i = 1; i < insertionOrder.size(); ++i) {
        size_t pendIndex = insertionOrder[i];
        binaryInsert(result, pend[pendIndex], result.size());
    }
    if (hasStraggler) {
        binaryInsert(result, straggler, result.size());
    }
    data = result;
}

void PmergeMe::printData(const std::vector<int>& data) {
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i];
        if (i < data.size() - 1) std::cout << " ";
    }
}

void PmergeMe::printData(const std::deque<int>& data) {
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i];
        if (i < data.size() - 1) std::cout << " ";
    }
}

bool PmergeMe::isSorted(const std::vector<int>& data) {
    for (size_t i = 1; i < data.size(); ++i) {
        if (data[i] < data[i - 1]) return false;
    }
    return true;
}

bool PmergeMe::isSorted(const std::deque<int>& data) {
    for (size_t i = 1; i < data.size(); ++i) {
        if (data[i] < data[i - 1]) return false;
    }
    return true;
}

void PmergeMe::sortAndMeasure() {
    std::cout << "Before: ";
    printData(vecData);
    std::cout << std::endl;
    clock_t start = clock();
    mergeInsertSort(vecData);
    clock_t end = clock();
    double vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    start = clock();
    mergeInsertSort(deqData);
    end = clock();
    double deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "After: ";
    printData(vecData);
    std::cout << std::endl;
    std::cout << "Time to process a range of " << vecData.size() 
              << " elements with std::vector : " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << deqData.size() 
              << " elements with std::deque : " << deqTime << " us" << std::endl;
}