/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:29:38 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:42:05 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
    public:
        Weapon(std::string type);
        ~Weapon();
    const std::string &getType();
    void setType(std::string newType);
    private:
    std::string _type;
};
    
#endif