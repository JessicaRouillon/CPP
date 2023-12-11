#include "WrongAnimal.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal is born into the world." << std::endl;
	this->_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	std::cout << "Copy of WrongAnimal is born into the world." << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal has died." << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& src)
{
	std::cout << "WrongAnimal overload operator (=) has been set." << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "This " << this->getType() << " says **BEEHHH** !" << std::endl;
}
