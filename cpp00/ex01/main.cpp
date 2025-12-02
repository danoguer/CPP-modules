/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eledion <eledion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:35:04 by eledion           #+#    #+#             */
/*   Updated: 2025/11/24 12:35:07 by eledion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iomanip>

int main()
{
    Phonebook mybook;
    std::string input;
    while (1)
    {
        std::cout << "Write ADD for adding a contact." << std::endl;
        std::cout << "Write SEARCH for look for a contact." << std::endl;
        std::cout << "Write EXIT for exit and delete everything." << std::endl;
        std::getline(std::cin, input);
        if (std::cin.eof()) break;
        if (input == "ADD")
        {
            mybook.add();
        }
        else if (input == "SEARCH")
        {
            mybook.search();
        }
        else if (input == "EXIT")
        {
            break;
        }
    }
    return 0;
}