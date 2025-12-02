/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:12:50 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:44:44 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- 1. CREATION ---" << std::endl;
    DiamondTrap d("Monster");

    std::cout << "\n--- 2. STATS CHECK ---" << std::endl;
    d.whoAmI();
    
    std::cout << "\n--- 3. ACTION ---" << std::endl;
    d.attack("Target");
    d.guardGate();
    d.highFivesGuys();
    std::cout << "\n--- 4. DESTRUCTION ---" << std::endl;
    return 0;
}