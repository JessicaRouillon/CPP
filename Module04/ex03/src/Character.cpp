#include "Character.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Character::Character()
{
}

Character::Character(const ICharacter& copy)
{
	*this = copy;
}

ICharacter::~Character()
{
}

Character	&Character::operator=(const Character& src)
{
	if (this != &src)
	{
		this->_name = src._name;
		for (size_t i = 0; i < 4; i++)
		{
			if (src._inventory[i])
				this->_inventory[i] = src._inventory[i];
		}
	}
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

void	Character::setName( std::string name )
{
	this->_name = name;
}

void	Character::setInventory( size_t i, AMateria* materia )
{
	this->_inventory[i] = materia;
}

const std::string&	Character::getName( std::string name ) const
{
	return (_name);
}

const AMateria*	Character::getInventory( size_t i ) const
{
	return (_inventory[i]);
}
