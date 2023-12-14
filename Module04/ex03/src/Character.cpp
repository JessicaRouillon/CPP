#include "Character.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Character::Character()
{
	this->_name = "Character with no name";
	for (size_t i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	// std::cout << "Character with no name enters the game." << std::endl;
}

Character::Character(std::string name)
{
	this->_name = name;
	for (size_t i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	// std::cout << "The character named "<< name << " enters the game." << std::endl;
}

Character::Character(const Character& copy)
{
	this->_name = copy._name;
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			this->_inventory[i] = copy._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	// std::cout << "Character "<< this->_name << " enters the game as a copy of " << copy._name << "." << std::endl;
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	// std::cout << "Character "<< this->_name << " has left the game." << std::endl;
}

Character	&Character::operator=(const Character& src)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
	}
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

// Getters & Setters
void	Character::setName( std::string name )
{
	this->_name = name;
}

void	Character::setInventory( size_t i, AMateria* materia )
{
	this->_inventory[i] = materia;
}

const std::string&	Character::getName( void ) const
{
	return (_name);
}

const AMateria*	Character::getInventory( size_t i ) const
{
	return (_inventory[i]);
}

// Functions
void	Character::equip(AMateria* m)
{
	if (!m)
	{
		// std::cout << "\033[0;31m" << "Cannot equip: Empty materia." << "\033[0m" << std::endl;
		return ;
	}
	size_t i = 0;
	while (this->_inventory[i] && i < 4)
		i++;
	if (i >= 4)
	{
		// std::cout << "\033[0;31m" 
		// 		<< "Cannot equip: " << this->_name
		// 		<< " already has 4 materiae in it's inventory."
		// 		<< "\033[0m" << std::endl;
		return ;
	}
	this->_inventory[i] = m;
	// std::cout << "\033[32m" << this->_name
	// 		<< " is now equipped with " << m->getType()
	// 		<< " in slot " << i << "." << "\033[0m" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		// std::cout << "\033[0;31m" 
		// 		<< "Cannot unequip: " << this->_name
		// 		<< " tried to unequip invalid inventory slot ("
		// 		<< idx << ")." << "\033[0m" << std::endl;
		return ;
	}
	if (this->_inventory[idx] == NULL)
	{
		// std::cout << "\033[0;31m"
		// 		<< "Cannot unequip: " << this->_name
		// 		<< "'s inventory slot " << idx
		// 		<< " is already empty." << "\033[0m" << std::endl;
		return ;
	}

	// AMateria*	tmp = this->_inventory[idx];
	// std::cout << this->_name << " unequipped " << tmp->getType() << " from inventory slot " << idx << "." << std::endl;
	this->_inventory[idx] = NULL;
	
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		// std::cout << "\033[0;31m" 
		// 		<< "Cannot use: " << this->_name
		// 		<< " tried to use materia from invalid inventory slot ("
		// 		<< idx << ")." << "\033[0m" << std::endl;
		return ;
	}
	if (this->_inventory[idx] == NULL)
	{
		// std::cout << "\033[0;31m"
		// 		<< "Cannot use: " << this->_name
		// 		<< "'s inventory slot " << idx
		// 		<< " is empty." << "\033[0m" << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}
