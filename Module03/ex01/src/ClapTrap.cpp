#include "ClapTrap.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

// Constructors

ClapTrap::ClapTrap()
{
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;

	std::cout << "ClapTrap has entered the battlefield (default constructor)." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;

	std::cout << "ClapTrap " << this->_name << " has entered the battlefield." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap " << this->_name << "'s copy has entered the battlefield." << std::endl;
	*this = copy;
}

// Destructor

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " has died or left the battlefiled." << std::endl;
}

// Move assignment operator: Overloaded operators
ClapTrap	&ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "ClapTrap " << this->_name << "'s copy assignment operator has entered the battlefield." << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

void ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " does not have enough Energy Points to attack." << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " cannot attack because he is dead." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		if (this->_hitPoints > amount)
		{
			this->_hitPoints -= amount;
			std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		}
		else
		{
			this->_hitPoints = 0;
			std::cout << "ClapTrap " << this->_name << " has lost all of it's Hit Points!" << std::endl;
		}
	}
	else
		std::cout << "ClapTrap " << this->_name << " cannot take damage because he is already dead." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0 && this->_hitPoints + amount <= 10)
	{
		std::cout << "ClapTrap " << this->_name << " has been repaired and gained " << amount << " Hit Points!" << std::endl;
		this->_energyPoints--;
		this->_hitPoints += amount;
	}
	else if (this->_hitPoints + amount > 10)
		std::cout << "ClapTrap " << this->_name << " cannot heal to have more than 10 Hit Points." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " does not have enough Energy Points to be repaired." << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " cannot be repaired because he is dead." << std::endl;
}
