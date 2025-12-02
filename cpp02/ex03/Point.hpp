/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:09:43 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:43:19 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
    Point();
    Point(const float x, const float y);
    Point(const Point &other);
    Point &operator=(const Point &other);
    ~Point();
    Fixed const getX( void ) const;
    Fixed const getY( void ) const;
private:
    Fixed const _x;
    Fixed const _y; 
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif