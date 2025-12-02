/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eledion <eledion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:02:47 by eledion           #+#    #+#             */
/*   Updated: 2025/11/25 12:07:47 by eledion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
public:
    HumanB(std::string name);
    ~HumanB();
    
    void setWeapon(Weapon &weapon);
    void attack();

private:
    std::string _name;
    Weapon *_weapon;
};
    
#endif