/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eledion <eledion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:09:49 by eledion           #+#    #+#             */
/*   Updated: 2025/11/27 12:16:12 by eledion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
public:
    Animal();
    virtual ~Animal();
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    virtual void makeSound() const = 0;
    std::string getType() const;
protected:
    std::string _type;
};

#endif