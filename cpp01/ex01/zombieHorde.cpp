/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eledion <eledion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:34:28 by eledion           #+#    #+#             */
/*   Updated: 2025/11/25 11:08:50 by eledion          ###   ########.fr       */
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
