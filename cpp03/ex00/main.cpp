/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eledion <eledion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:12:50 by eledion           #+#    #+#             */
/*   Updated: 2025/11/27 10:13:19 by eledion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    std::cout << "--- FIGHT START ---" << std::endl;
    
    ClapTrap robotA("Terminator");
    ClapTrap robotB("RoboCop");

    robotA.attack("RoboCop");
    robotB.takeDamage(0); 
    robotB.attack("Terminator");
    robotA.takeDamage(5);

    robotA.beRepaired(3);

    std::cout << "\n--- EXHAUSTION TEST ---" << std::endl;
    for (int i = 0; i < 12; i++)
    {
        robotA.attack("Air");
    }

    std::cout << "\n--- DEATH TEST ---" << std::endl;
    robotB.takeDamage(20);
    robotB.attack("Terminator");
    robotB.beRepaired(10);
    std::cout << "\n--- FIGHT END ---" << std::endl;
    return 0;
}