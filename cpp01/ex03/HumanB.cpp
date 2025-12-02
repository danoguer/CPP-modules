/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:04:06 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:41:51 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
    this->_weapon = NULL;
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

void HumanB::attack()
{
    if (this->_weapon != NULL)
    {
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    }
    else
    {
        std::cout << this->_name << " has no weapon" << std::endl;
    }
}