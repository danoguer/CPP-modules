/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:46:31 by danoguer          #+#    #+#             */
/*   Updated: 2025/12/02 11:46:32 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{

    std::cout << "--- TEST 1: SUBJECT WALKTHROUGH ---" << std::endl;
    
    IMateriaSource* src = new MateriaSource();
    

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    
    tmp = src->createMateria("ice");
    me->equip(tmp);
    
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

  
    me->use(0, *bob);
    me->use(1, *bob);


    delete bob;
    delete me;
    delete src;

    std::cout << "\n--- TEST 2: INVENTORY LIMITS & UNEQUIP ---" << std::endl;

    IMateriaSource* magicBook = new MateriaSource();
    magicBook->learnMateria(new Ice());
    magicBook->learnMateria(new Cure());

    ICharacter* hero = new Character("Hero");

    std::cout << "[Equipping 5 items...]" << std::endl;
    hero->equip(magicBook->createMateria("ice"));
    hero->equip(magicBook->createMateria("cure"));
    hero->equip(magicBook->createMateria("ice"));
    hero->equip(magicBook->createMateria("cure"));
    AMateria* extra = magicBook->createMateria("ice");
    hero->equip(extra); 
    std::cout << "\n[Unequipping slot 0...]" << std::endl;
    hero->unequip(0); 
    std::cout << "[Using empty slot 0...]" << std::endl;
    hero->use(0, *hero);

    delete extra;
    delete hero;
    delete magicBook;


    std::cout << "\n--- TEST 3: DEEP COPY ---" << std::endl;

    Character* original = new Character("Original");
    original->equip(new Ice());
    original->equip(new Cure());

    Character* clone = new Character(*original);
    original->unequip(0); 

    std::cout << "Original uses slot 0 (Should do nothing): ";
    original->use(0, *clone);

    std::cout << "Clone uses slot 0 (Should still be Ice): ";
    clone->use(0, *original);

    delete original;
    delete clone;

    return 0;
}