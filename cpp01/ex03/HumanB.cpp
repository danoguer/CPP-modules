/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eledion <eledion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:04:06 by eledion           #+#    #+#             */
/*   Updated: 2025/11/25 12:10:33 by eledion          ###   ########.fr       */
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