#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

    // Additional simple tests
    std::cout << "\n=== Additional Tests ===" << std::endl;
    
    // Test 1: Empty array
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    
    // Test 2: Array of strings
    Array<std::string> strings(3);
    strings[0] = "Hello";
    strings[1] = "42";
    strings[2] = "World";
    std::cout << "Strings: " << strings[0] << " " << strings[1] << " " << strings[2] << std::endl;
    
    // Test 3: Assignment operator
    Array<int> arr1(2);
    arr1[0] = 100;
    arr1[1] = 200;
    Array<int> arr2 = arr1;
    arr2[0] = 999;
    std::cout << "Original: " << arr1[0] << ", Copy: " << arr2[0] << std::endl;

    return 0;
}