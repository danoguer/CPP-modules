/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eledion <eledion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:50:56 by eledion           #+#    #+#             */
/*   Updated: 2025/11/25 11:50:57 by eledion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();
    
    void attack();

private:
    std::string _name;
    Weapon &_weapon;
};
    
#endif