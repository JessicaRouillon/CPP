#include "Animal.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Animal::Animal()
{
	std::cout << "Animal is born into the world." << std::endl;
	this->_type = "Animal";
}

Animal::Animal(const Animal& copy)
{
	std::cout << "Copy of Animal is born into the world." << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Animal has died." << std::endl;
}

Animal	&Animal::operator=(const Animal& src)
{
	std::cout << "Animal overload operator (=) has been set." << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

std::string	Animal::getType(void) const
{
	return (this->_type);
}

