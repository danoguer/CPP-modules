/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eledion <eledion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:15:45 by eledion           #+#    #+#             */
/*   Updated: 2025/11/25 12:23:42 by eledion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replace_file(std::string filename, std::string s1, std::string s2)
{
    std::ifstream inFile(filename.c_str());
    if (!inFile.is_open())
    {
        std::cerr << "Error: Cannot open input file." << std::endl;
        return;
    }
    std::string content;
    std::string line;
    while (std::getline(inFile, line))
    {
        content += line;
        if (!inFile.eof())
            content += "\n";
    }
    inFile.close();
    if (!s1.empty())
    {
        size_t pos = 0;
        while (true)
        {
            pos = content.find(s1, pos);
            if (pos == std::string::npos)
                break;
            content.erase(pos, s1.length());
            content.insert(pos, s2);
            pos += s2.length();
        }
    }
    std::string outName = filename + ".replace";
    std::ofstream outFile(outName.c_str());
    if (!outFile.is_open())
    {
        std::cerr << "Error: Cannot create output file." << std::endl;
        return;
    }
    outFile << content;
    outFile.close();
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: ./sed <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    replace_file(argv[1], argv[2], argv[3]);
    return 0;
}