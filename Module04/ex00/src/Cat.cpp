#include "Cat.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Cat::Cat()
{
	std::cout << "Cat is born into the world." << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat& copy)
{
	std::cout << "Copy of Cat is born into the world." << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	std::cout << "Cat has died." << std::endl;
}

Cat	&Cat::operator=(const Cat& src)
{
	std::cout << "Cat overload operator (=) has been set." << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}


/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

void	Cat::makeSound(void) const
{
	std::cout << "The " << this->getType() << " says **MEEOOWWW** !" << std::endl;
}
