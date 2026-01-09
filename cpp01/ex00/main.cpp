/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:21:39 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:39:17 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::cout << "\n--- Creating Heap Zombie ---" << std::endl;
    Zombie *z = newZombie("Chus");
    z->announce();
    delete z;
    
    std::cout << "--- Creating Stack Zombie ---" << std::endl;
    randomChump("Fernando");
    return 0;
}