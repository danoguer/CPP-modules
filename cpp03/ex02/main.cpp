/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:12:50 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:44:14 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "--- 1. FRAGTRAP CREATION ---" << std::endl;
    FragTrap frag("Bomber");

    std::cout << "\n--- 2. FRAGTRAP ACTION ---" << std::endl;
    frag.attack("Target");
    frag.highFivesGuys();

    std::cout << "\n--- 3. DESTRUCTION ---" << std::endl;
    return 0;
}