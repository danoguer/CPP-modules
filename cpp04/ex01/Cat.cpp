/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eledion <eledion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:46:26 by eledion           #+#    #+#             */
/*   Updated: 2025/11/27 12:13:50 by eledion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->_type = "Cat";
    this->_brain = new Brain();
    std::cout << "Cat Constructor called" << std::endl;
}

Cat::~Cat()
{
    delete this->_brain;
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat Deep Copy Constructor called" << std::endl;
    this->_brain = new Brain( *other._brain );
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat Deep Assignment Operator called" << std::endl;
     if (this != &other)
    {
        Animal::operator=(other);
        delete this->_brain;
        this->_brain = new Brain( *other._brain );
    }
    return *this;
}

