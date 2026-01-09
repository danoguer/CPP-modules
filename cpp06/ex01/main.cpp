#include "Serializer.hpp"
#include <iostream>

int main() {
    Data myData;
    myData.id = 42;
    myData.name = "Gemini";
    myData.metadata = "Testing Serialization";

    std::cout << "Original Pointer:    " << &myData << std::endl;

    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "Serialized (uint):   " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized Pointer: " << ptr << std::endl;

    if (ptr == &myData) {
        std::cout << "Success! Pointers match." << std::endl;
        std::cout << "Data check - Name: " << ptr->name << std::endl;
    } else {
        std::cout << "Error! Pointers do not match." << std::endl;
    }

    return 0;
}