#include "DiamondTrap.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

// Constructors

DiamondTrap::DiamondTrap(): ClapTrap("DefaultDiamondTrap_clap_trap")
{
	this->_name = "DefaultDiamondTrap";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap has entered the battlefield (default constructor)." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_trap")
{
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << this->_name << " has entered the battlefield." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << "DiamondTrap " << this->_name << "'s copy has entered the battlefield." << std::endl;
	(*this) = copy;
}

// Destructor

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " has died or left the battlefield." << std::endl;
}

// Move assignment operator: Overloaded operators
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << "DiamondTrap " << this->_name << "'s copy assignment operator has entered the battlefield." << std::endl;
	this->_name = src._name + "_clap_trap";
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return (*this);
}


/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am DiamondTrap named " << this->_name
			<< " and my ClapTrap name is " << ClapTrap::_name
			<< "." << std::endl;
}
