#include "HumanB.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

// Constructor
HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_is_armed = false;
	std::cout << name << " has entered the battlefield unarmed." << std::endl;
}

// Destructor
HumanB::~HumanB()
{
	std::cout << this->_name << " has died or left the battlefield." << std::endl;
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

void	HumanB::attack(void) const
{
	if (this->_is_armed == true)
	{
		std::cout << this->_name
				<< " attacks with "
				<< this->_weapon->getType()
				<< "."
				<< std::endl;
	}
	else
	{
		std::cout << this->_name
				<< " attacks with their fists."
				<< std::endl;
	}
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	this->_is_armed = true;
	std::cout << this->_name
			<< " has grabbed a "
			<< this->_weapon->getType()
			<< "."
			<< std::endl;
}
