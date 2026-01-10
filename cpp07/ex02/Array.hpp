#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template <typename T>
class Array {
private:
    T* _elements;
    size_t _size;
public:
    Array() : _elements(NULL), _size(0) {}
    
    Array(unsigned int n) : _elements(new T[n]()), _size(n) {}
    
    Array(const Array &other) : _elements(new T[other._size]), _size(other._size) {
        for (size_t i = 0; i < _size; i++) {
            _elements[i] = other._elements[i];
        }
    }

    Array &operator=(const Array &other) {
        if (this != &other) {
            delete[] _elements;
            _size = other._size;
            _elements = new T[_size];
            for (size_t i = 0; i < _size; i++) {
                _elements[i] = other._elements[i];
            }
        }
        return *this;
    }

    ~Array(){
        delete[] _elements;
    }

    T &operator[](size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _elements[index];
    }

    const T &operator[](size_t index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _elements[index];
    }

    size_t size() const { return _size; }
};

#endif