/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eledion <eledion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:35:12 by eledion           #+#    #+#             */
/*   Updated: 2025/11/24 12:47:04 by eledion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"
# include <iomanip>
# include <cstdlib>

class Phonebook
{
public:
    Phonebook();
    ~Phonebook();
    
    void add();
    void search();

private:
    Contact contacts[8];
    int     index;
    std::string getInput(std::string prompt);
};

#endif