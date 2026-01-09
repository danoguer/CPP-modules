/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:11:49 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:41:41 by danoguer         ###   ########.fr       */
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