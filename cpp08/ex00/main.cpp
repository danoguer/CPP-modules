#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "EasyFind.hpp"

int main(void) {
    std::cout << "=== Test 1: Vector ===" << std::endl;
    {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        vec.push_back(40);
        vec.push_back(50);

        std::vector<int>::iterator it = easyfind(vec, 30);
        if (it != vec.end())
            std::cout << "Found: " << *it << std::endl;
        else
            std::cout << "Not found" << std::endl;

        it = easyfind(vec, 99);
        if (it != vec.end())
            std::cout << "Found: " << *it << std::endl;
        else
            std::cout << "Not found (expected)" << std::endl;
    }

    std::cout << "\n=== Test 2: List ===" << std::endl;
    {
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(15);
        lst.push_back(25);
        lst.push_back(35);

        std::list<int>::iterator it = easyfind(lst, 15);
        if (it != lst.end())
            std::cout << "Found: " << *it << std::endl;
        else
            std::cout << "Not found" << std::endl;

        it = easyfind(lst, 100);
        if (it != lst.end())
            std::cout << "Found: " << *it << std::endl;
        else
            std::cout << "Not found (expected)" << std::endl;
    }

    std::cout << "\n=== Test 3: Deque ===" << std::endl;
    {
        std::deque<int> deq;
        deq.push_back(1);
        deq.push_back(2);
        deq.push_back(3);
        deq.push_back(4);

        std::deque<int>::iterator it = easyfind(deq, 1);
        if (it != deq.end())
            std::cout << "Found first element: " << *it << std::endl;
        else
            std::cout << "Not found" << std::endl;

        it = easyfind(deq, 4);
        if (it != deq.end())
            std::cout << "Found last element: " << *it << std::endl;
        else
            std::cout << "Not found" << std::endl;
    }

    std::cout << "\n=== Test 4: Empty container ===" << std::endl;
    {
        std::vector<int> empty;
        std::vector<int>::iterator it = easyfind(empty, 42);
        if (it != empty.end())
            std::cout << "Found: " << *it << std::endl;
        else
            std::cout << "Not found in empty container (expected)" << std::endl;
    }

    return 0;
}
