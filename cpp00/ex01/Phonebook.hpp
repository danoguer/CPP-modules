/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:35:12 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:39:11 by danoguer         ###   ########.fr       */
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