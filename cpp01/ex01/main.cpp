/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:21:39 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:41:32 by danoguer         ###   ########.fr       */
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