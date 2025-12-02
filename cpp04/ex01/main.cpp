/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:45:41 by danoguer          #+#    #+#             */
/*   Updated: 2025/12/02 11:45:42 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "--- 1. ARRAY OF ANIMALS TEST ---" << std::endl;
    
    const int count = 4;
    Animal* animals[count];

    for (int i = 0; i < count / 2; i++)
        animals[i] = new Dog();
    
    for (int i = count / 2; i < count; i++)
        animals[i] = new Cat();

    std::cout << "\n--- Deleting Array... ---" << std::endl;
    
    for (int i = 0; i < count; i++)
        delete animals[i];


    std::cout << "\n--- 2. DEEP COPY TEST ---" << std::endl;
    
    Dog basic;
    {
        Dog tmp = basic; 
    } 
    std::cout << "\n--- END OF MAIN ---" << std::endl;
    return 0;
}