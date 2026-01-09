/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:59:41 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:41:34 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
    std::cout << "Zombie " << this->_name << " created." << std::endl;
}

Zombie::Zombie()
{
    this->_name = "(Waiting for name...)"; 
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->_name << " is dead." << std::endl;
}

void Zombie::setName(std::string name) { this->_name = name; }

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

