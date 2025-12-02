/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:34:28 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:41:38 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *horde = new Zombie[N];
    for (int i = 0; i < N; ++i)
    {
        std::stringstream ss;
        ss << i + 1;
        std::string finalName = name + "_" + ss.str();
        horde[i].setName(finalName);
    }
    return horde;
}
