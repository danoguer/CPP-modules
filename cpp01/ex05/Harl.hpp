/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eledion <eledion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:42:49 by eledion           #+#    #+#             */
/*   Updated: 2025/11/25 13:00:38 by eledion          ###   ########.fr       */
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