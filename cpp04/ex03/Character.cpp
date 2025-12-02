
#include "Character.hpp"

Character::Character()
{
    std::cout << "Character constructor is called" << std::endl;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::~Character()
{
    std::cout << "Character destructor is called" << std::endl;
    for (int i = 0; i < 4; i++)
        delete _inventory[i];
}

Character::Character(std::string const & name) : _name(name)
{
    std::cout << "Character " << _name << " created" << std::endl;
    
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL; 
}

Character::Character(const Character &other) 
{
    std::cout << "Character Copy Constructor called" << std::endl;
    
    this->_name = other.getName(); 
    for (int i = 0; i < 4; i++)
    {
        this->_inventory[i] = NULL;
    }
    for (int i = 0; i < 4; i++)
    {
        if (other._inventory[i] != NULL)
        {
            this->_inventory[i] = other._inventory[i]->clone();
        }
    }
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        this->_name = other.getName();

        for (int i = 0; i < 4; i++)
        {
            if (this->_inventory[i] != NULL)
            {
                delete this->_inventory[i];
                this->_inventory[i] = NULL;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (other._inventory[i] != NULL)
                this->_inventory[i] = other._inventory[i]->clone();
        }
    }
    return *this;
}

std::string const &Character::getName() const
{
    return this->_name; 
}

void Character::equip(AMateria* m)
{
    if (!m) 
        return;
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] == NULL)
        {
            this->_inventory[i] = m;
            std::cout << "Character " << this->_name << " equipped " << m->getType() << " at slot " << i << std::endl;
            return;
        }
    }
    std::cout << "Character " << this->_name << "'s inventory is full!" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
        this->_inventory[idx]->use(target);
}
