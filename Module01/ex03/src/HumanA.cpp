#include "HumanA.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

// Constructor
HumanA::HumanA(std::string name, Weapon& weapon):_weapon(weapon)
{
	this->_name = name;
	std::cout << name
			<< " has entered the battlefield armed with a "
			<< this->_weapon.getType()
			<< "."
			<< std::endl;
}

// Destructor
HumanA::~HumanA()
{
	std::cout << this->_name << " has died or left the battlefield." << std::endl;
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

void	HumanA::attack(void) const
{
	std::cout << this->_name
			<< " attacks with "
			<< this->_weapon.getType()
			<< "."
			<< std::endl;
}
