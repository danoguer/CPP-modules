/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:01:55 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:42:49 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = n << _fractionalBits; 
}

Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(n * (1 << _fractionalBits));
}

int Fixed::toInt( void ) const
{
    return this->_fixedPointValue >> _fractionalBits;
}

float Fixed::toFloat( void ) const
{
    return (float)this->_fixedPointValue / (float)(1 << _fractionalBits);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits( int const raw )
{
    this->_fixedPointValue = raw;
}

//Used to change Fixed to Float and send it to cout.
std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
    o << i.toFloat();
    return o;
}
