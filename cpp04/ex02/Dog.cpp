/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:46:18 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:46:00 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->_type = "Dog";
    this->_brain = new Brain();
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::~Dog()
{
    delete this->_brain;
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog Deep Copy Constructor called" << std::endl;
    this->_brain = new Brain( *other._brain );
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog Deep Assignment Operator called" << std::endl;
     if (this != &other)
    {
        Animal::operator=(other);
        delete this->_brain;
        this->_brain = new Brain( *other._brain );
    }
    return *this;
}


