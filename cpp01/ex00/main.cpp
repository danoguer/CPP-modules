/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eledion <eledion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:21:39 by eledion           #+#    #+#             */
/*   Updated: 2025/11/25 10:29:39 by eledion          ###   ########.fr       */
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