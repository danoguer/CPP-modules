/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eledion <eledion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:59:44 by eledion           #+#    #+#             */
/*   Updated: 2025/11/25 10:58:56 by eledion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
    void announce();
    void setName(std::string name);
    private:
    std::string _name;
};

Zombie* zombieHorde( int N, std::string name );
    
#endif