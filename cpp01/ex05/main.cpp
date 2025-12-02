/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:46:30 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:42:26 by danoguer         ###   ########.fr       */
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