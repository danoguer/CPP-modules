/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eledion <eledion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:46:30 by eledion           #+#    #+#             */
/*   Updated: 2025/11/25 12:58:56 by eledion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Error: Only one parameter needed" << std::endl;
        return 1;
    }
    std::string level = argv[1];
    if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
    {
        std::cout << "Error: Parameter not valid" << std::endl;
        return 1;
    }
    Harl harl;
    harl.complain(level);
    return 0;
}