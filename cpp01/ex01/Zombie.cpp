/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eledion <eledion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:59:41 by eledion           #+#    #+#             */
/*   Updated: 2025/11/25 11:04:15 by eledion          ###   ########.fr       */
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

