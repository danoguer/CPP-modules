/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:04:37 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:43:00 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
public:

    Fixed();
    Fixed(const int n);
    Fixed(const float n);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    float toFloat( void ) const;
    int   toInt( void ) const;

    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;
    Fixed &operator++( void ); 
    Fixed operator++( int );   

    Fixed &operator--( void );
    Fixed operator--( int );

    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif