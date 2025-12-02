/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:55:12 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:45:11 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << "WrongAnimal Constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal Sound (Generic)" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->_type;
}