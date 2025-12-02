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
