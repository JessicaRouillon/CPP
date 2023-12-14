#include "FragTrap.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

// Constructors

FragTrap::FragTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap has entered the battlefield (default constructor)." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " has entered the battlefield." << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap " << this->_name << "'s copy has entered the battlefield." << std::endl;
	(*this) = copy;
}

// Destructor

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " has died or left the battlefield." << std::endl;
}

// Move assignment operator: Overloaded operators
FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "FragTrap " << this->_name << "'s copy assignment operator has entered the battlefield." << std::endl;
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

// Give High Fives
void FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints == 0)
		std::cout << "FragTrap " << this->_name << " cannot give high fives because he is dead." << std::endl;
	else
		std::cout << "\033[0;35m"
				  << "FragTrap " << this->_name << " gives a high five!"
				  << "\033[0m" << std::endl;
}
