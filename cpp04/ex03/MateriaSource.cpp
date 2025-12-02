
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->_templates[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_templates[i] != NULL)
            delete this->_templates[i];
    }
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i = 0; i < 4; i++)
    {
        this->_templates[i] = NULL; // Init
        if (other._templates[i] != NULL)
            this->_templates[i] = other._templates[i]->clone();
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->_templates[i] != NULL)
                delete this->_templates[i];
            this->_templates[i] = NULL;
        }

        for (int i = 0; i < 4; i++)
        {
            if (other._templates[i] != NULL)
                this->_templates[i] = other._templates[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m) 
        return;
    for (int i = 0; i < 4; i++)
    {
        if (this->_templates[i] == NULL)
        {
            this->_templates[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_templates[i] != NULL && this->_templates[i]->getType() == type)
        {
            return this->_templates[i]->clone();
        }
    }
    return 0;
}