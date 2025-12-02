/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:01:55 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:42:58 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = n << _fractionalBits; 
}

Fixed::Fixed(const float n) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(n * (1 << _fractionalBits));
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
    this->_fixedPointValue = raw;
}

int Fixed::toInt( void ) const {
    return this->_fixedPointValue >> _fractionalBits;
}

float Fixed::toFloat( void ) const {
    return (float)this->_fixedPointValue / (float)(1 << _fractionalBits);
}

//Comparison Operators.
bool Fixed::operator>(const Fixed &other) const {
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const {
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->getRawBits() != other.getRawBits();
}

// Arithmetic Operators.
Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

// Increment / Decrement.
Fixed &Fixed::operator++(void) {
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->_fixedPointValue++;
    return temp;
}

Fixed &Fixed::operator--(void) {
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->_fixedPointValue--;
    return temp;
}

// Compare and return.
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
    o << i.toFloat();
    return o;
}
