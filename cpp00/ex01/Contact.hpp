/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:35:19 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:39:01 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
public:
    Contact();
    ~Contact();
    
    void setFirstname(std::string str);
    std::string getFirstname();
    
    void setLastname(std::string str);
    std::string getLastname();

    void setNickname(std::string str);
    std::string getNickname();

    void setPhonenumber(std::string str);
    std::string getPhonenumber();

    void setDarkestsecret(std::string str);
    std::string getDarkestsecret();

private:
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string phonenumber;
    std::string darkestsecret;
};

#endif