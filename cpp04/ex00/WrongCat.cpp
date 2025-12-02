/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:56:25 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:45:13 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->_type = "WrongCat";
    std::cout << "WrongCat Constructor" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat Meow!" << std::endl;
}