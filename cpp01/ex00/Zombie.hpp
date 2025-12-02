/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eledion <eledion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:59:44 by eledion           #+#    #+#             */
/*   Updated: 2025/11/25 10:31:50 by eledion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
    public:
        Zombie(std::string name);
        ~Zombie();
    void announce();
    private:
    std::string _name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );
    
#endif