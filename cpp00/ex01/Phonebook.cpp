/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eledion <eledion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:35:09 by eledion           #+#    #+#             */
/*   Updated: 2025/11/24 12:42:49 by eledion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook() 
{
    this->index = 0;
}
Phonebook::~Phonebook() 
{ 
}

std::string Phonebook::getInput(std::string prompt)
{
    std::string input = "";

    while (true)
    {
        std::cout << prompt << std::flush;
        std::getline(std::cin, input);
        if (std::cin.eof()) 
            exit(0);
        if (!input.empty())
            return (input);
        std::cout << "   Field cannot be empty. Try again." << std::endl;
    }
}

void Phonebook::add()
{
    std::cout << "--- Adding New Contact ---" << std::endl;
    
    this->contacts[this->index].setFirstname(getInput("Enter First Name: "));
    this->contacts[this->index].setLastname(getInput("Enter Last Name: "));
    this->contacts[this->index].setNickname(getInput("Enter Nickname: "));
    this->contacts[this->index].setPhonenumber(getInput("Enter Phone Number: "));
    this->contacts[this->index].setDarkestsecret(getInput("Enter Darkest Secret: "));
    std::cout << "Successfully added to index " << this->index << "!" << std::endl;
    this->index++;
    
    if (this->index == 8)
        this->index = 0;
}

void Phonebook::search()
{
    int i = 0; 

    std::cout << " ___________________________________________ " << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|__________|__________|__________|__________|" << std::endl;

    while (i < 8)
    {
        if (this->contacts[i].getFirstname().empty()) 
        {
            i++; 
            continue;
        }
        std::string str;
        std::cout << "|" << std::setw(10) << i;
        str = contacts[i].getFirstname();
        if (str.length() > 10)
            str = str.substr(0, 9) + ".";
        std::cout << "|" << std::setw(10) << str;
        str = contacts[i].getLastname();
        if (str.length() > 10)
            str = str.substr(0, 9) + ".";
        std::cout << "|" << std::setw(10) << str;
        str = contacts[i].getNickname();
        if (str.length() > 10)
            str = str.substr(0, 9) + ".";
        std::cout << "|" << std::setw(10) << str;

        std::cout << "|" << std::endl;
        
        i++;
    }
    std::cout << " ------------------------------------------- " << std::endl;
    int indexInput;
    std::cout << "Enter Index to view details: ";
    std::cin >> indexInput;
    if (std::cin.fail() || indexInput < 0 || indexInput > 7 || contacts[indexInput].getFirstname().empty())
    {
        std::cin.clear();
        std::cout << "Invalid Index." << std::endl;
    }
    else
    {
        std::cout << "First Name: " << contacts[indexInput].getFirstname() << std::endl;
        std::cout << "Last Name: " << contacts[indexInput].getLastname() << std::endl;
        std::cout << "Nick Name: " << contacts[indexInput].getNickname() << std::endl;
        std::cout << "Phone Number: " << contacts[indexInput].getPhonenumber() << std::endl;
        std::cout << "Darkest Secret: " << contacts[indexInput].getDarkestsecret() << std::endl;
    }
    std::cin.ignore(1000, '\n');
}