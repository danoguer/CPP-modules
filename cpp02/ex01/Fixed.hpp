/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eledion <eledion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:04:37 by eledion           #+#    #+#             */
/*   Updated: 2025/11/26 11:25:33 by eledion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
#include <cmath>

class Fixed
{
public:

    Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();
    Fixed(const int n);
    Fixed(const float n);
    
    int toInt( void ) const;
    float toFloat( void ) const;
    int getRawBits( void ) const;
    void setRawBits( int const raw);

private:
    int              _fixedPointValue;
    static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif