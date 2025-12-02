/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eledion <eledion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:29:38 by eledion           #+#    #+#             */
/*   Updated: 2025/11/25 11:33:30 by eledion          ###   ########.fr       */
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