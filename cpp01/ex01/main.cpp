/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eledion <eledion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:21:39 by eledion           #+#    #+#             */
/*   Updated: 2025/11/25 11:01:14 by eledion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int i = 0;
    int N = 6;
    std::string name = "Pedro";
    std::cout << "\n--- Creating Zombie Horde ---" << std::endl;
    Zombie *horde =zombieHorde(N, name);
    while (i < N)
    {
        horde[i].announce();
        i++;
    }
    delete[] horde;
    return 0;
}