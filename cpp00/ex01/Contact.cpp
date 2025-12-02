/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:35:21 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:38:58 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() 
{ 
}
Contact::~Contact() 
{ 
}

void Contact::setFirstname(std::string str) 
{
    this->firstname = str; 
}

std::string Contact::getFirstname() 
{ 
    return this->firstname; 
}

void Contact::setLastname(std::string str) 
{
    this->lastname = str; 
}

std::string Contact::getLastname() 
{ 
    return this->lastname; 
}

void Contact::setNickname(std::string str) 
{
    this->nickname = str; 
}

std::string Contact::getNickname() 
{ 
    return this->nickname; 
}

void Contact::setPhonenumber(std::string str) 
{
    this->phonenumber = str; 
}

std::string Contact::getPhonenumber()
{ 
    return this->phonenumber; 
}

void Contact::setDarkestsecret(std::string str) 
{
    this->darkestsecret = str; 
}

std::string Contact::getDarkestsecret()
{ 
    return this->darkestsecret; 
}