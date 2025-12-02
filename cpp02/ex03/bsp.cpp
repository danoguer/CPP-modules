/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:09:36 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:43:07 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed abs(Fixed x) {
    if (x < 0)
        return x * -1;
    return x;
}

static Fixed calculateArea(Point const a, Point const b, Point const c)
{
    Fixed term1 = a.getX() * (b.getY() - c.getY());
    Fixed term2 = b.getX() * (c.getY() - a.getY());
    Fixed term3 = c.getX() * (a.getY() - b.getY());

    Fixed area = (term1 + term2 + term3) / 2;
    return abs(area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed totalArea = calculateArea(a, b, c);
    Fixed area1 = calculateArea(point, a, b);
    Fixed area2 = calculateArea(point, b, c);
    Fixed area3 = calculateArea(point, c, a);

    if (area1 == 0 || area2 == 0 || area3 == 0)
        return false;

    if ((area1 + area2 + area3) == totalArea)
        return true;

    return false;
}