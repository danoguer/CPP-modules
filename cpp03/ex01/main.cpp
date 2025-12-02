/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eledion <eledion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:12:50 by eledion           #+#    #+#             */
/*   Updated: 2025/11/27 10:36:23 by eledion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    std::cout << "--- 1. CREATION ---" << std::endl;
    ScavTrap robot("Guardian"); // Should print ClapTrap born -> ScavTrap born

    std::cout << "\n--- 2. ACTION ---" << std::endl;
    robot.attack("Intruder"); // Should print "ScavTrap attacks..." (20 damage)
    robot.guardGate();        // Should print "Gate keeper mode"

    std::cout << "\n--- 3. DESTRUCTION ---" << std::endl;
    // Should print ScavTrap die -> ClapTrap die
    return 0;
}