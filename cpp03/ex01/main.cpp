/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:12:50 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:43:51 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    std::cout << "--- 1. CREATION ---" << std::endl;
    ScavTrap robot("Guardian");

    std::cout << "\n--- 2. ACTION ---" << std::endl;
    robot.attack("Intruder");
    robot.guardGate();

    std::cout << "\n--- 3. DESTRUCTION ---" << std::endl;
    return 0;
}