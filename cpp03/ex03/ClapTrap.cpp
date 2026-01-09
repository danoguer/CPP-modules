/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 09:43:25 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:44:30 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap constructor is called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        std::cout << "Claptrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage! " << std::endl;
        this->_energyPoints--;
    }
    else
    {
        std::cout << "ClapTrap " << this->_name << " is too tired or dead to attack." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints > 0)
    {
        if ((int)amount >= this->_hitPoints)
            this->_hitPoints = 0;
        else
            this->_hitPoints -= amount;
            
        std::cout << "ClapTrap " << this->_name << " took " << amount << " damage! HP is now " << this->_hitPoints << "." << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        this->_energyPoints--;
        this->_hitPoints += amount;
        
        std::cout << "ClapTrap " << this->_name << " repaired itself for " << amount << " HP! Current HP: " << this->_hitPoints << "." << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << this->_name << " is too tired or dead to repair." << std::endl;
    }
}

