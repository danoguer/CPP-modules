/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:46:36 by danoguer          #+#    #+#             */
/*   Updated: 2025/12/02 11:46:37 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
    MateriaSource();
    virtual ~MateriaSource();
    MateriaSource(const MateriaSource &other);
    MateriaSource &operator=(const MateriaSource &other);

    virtual void learnMateria(AMateria*);
    virtual AMateria* createMateria(std::string const & type);
private:
    AMateria* _templates[4];
};

#endif
