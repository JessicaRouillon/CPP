#include "Zombie.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

// Constructor
Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << this->_name << " has been created." << std::endl;
}

// Destructor
Zombie::~Zombie()
{
	std::cout << this->_name << " has been destroyed." << std::endl;
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
