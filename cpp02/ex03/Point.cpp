/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:09:40 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:43:17 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
}

Point::Point(const Point &other) : _x(other.getX()), _y(other.getY()) {   
}

Point &Point::operator=(const Point &other) {
    (void)other;
    return *this;
}

Point::~Point() {
}

Fixed const Point::getX( void ) const {
    return this->_x;
}

Fixed const Point::getY( void ) const {
    return this->_y;
}
