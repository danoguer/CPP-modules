/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:22:35 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:44:55 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
     if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "* Generic Animal Noises *" << std::endl;
}

std::string Animal::getType() const
{
    return this->_type;
}