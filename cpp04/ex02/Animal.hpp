/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:09:49 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:45:48 by danoguer         ###   ########.fr       */
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