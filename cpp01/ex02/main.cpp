/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eledion <eledion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:11:49 by eledion           #+#    #+#             */
/*   Updated: 2025/11/25 11:25:52 by eledion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string *pointer = &string;
    std::string &reference = string;
    std::cout << "Adress of string: " << &string << std::endl;
    std::cout << "Adress held by pointer: " << pointer << std::endl;
    std::cout << "Adress of reference: " << &reference << std::endl;
    std::cout << "Value of string: " << string << std::endl;
    std::cout << "Value pointed by pointer: " << *pointer << std::endl;
    std::cout << "Value referred to by reference: " << reference << std::endl;
}