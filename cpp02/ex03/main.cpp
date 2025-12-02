/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eledion <eledion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:09:34 by eledion           #+#    #+#             */
/*   Updated: 2025/11/26 13:07:51 by eledion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main( void ) {
    
    Point a(0, 0);
    Point b(20, 0);
    Point c(10, 30);

    Point p1(10, 15);
    if (bsp(a, b, c, p1))
        std::cout << "Point 1 is INSIDE (Correct)" << std::endl;
    else
        std::cout << "Point 1 is OUTSIDE (Wrong)" << std::endl;

    Point p2(30, 15);
    if (bsp(a, b, c, p2))
        std::cout << "Point 2 is INSIDE (Wrong)" << std::endl;
    else
        std::cout << "Point 2 is OUTSIDE (Correct)" << std::endl;

    Point p3(10, 0);
    if (bsp(a, b, c, p3))
        std::cout << "Point 3 is INSIDE (Wrong - Edge)" << std::endl;
    else
        std::cout << "Point 3 is OUTSIDE (Correct - Edge)" << std::endl;

    if (bsp(a, b, c, a))
        std::cout << "Point 4 is INSIDE (Wrong - Vertex)" << std::endl;
    else
        std::cout << "Point 4 is OUTSIDE (Correct - Vertex)" << std::endl;

    return 0;
}
