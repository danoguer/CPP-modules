/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:46:26 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:44:59 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->_type = "Cat";
    std::cout << "Cat Constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
}

Cat &Cat::operator=(const Cat &other)
{
     if (this != &other)
    {
        Animal::operator=(other);
    }
    return *this;
}


