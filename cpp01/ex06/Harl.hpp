/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:42:49 by eledion           #+#    #+#             */
/*   Updated: 2025/12/02 11:42:33 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
public:
    Harl();
    ~Harl();  
    void complain( std::string level ); 
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
};

#endif