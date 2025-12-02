/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:50:56 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:41:49 by danoguer         ###   ########.fr       */
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