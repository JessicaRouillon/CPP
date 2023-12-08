#include "Cat.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Cat::Cat()
{
	std::cout << "Cat is born into the world." << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		std::cout << "Brain allocation error for Cat." << std::endl;
		exit(1);
	}
}

Cat::Cat(const Cat& copy)
{
	std::cout << "Copy of Cat is born into the world." << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	std::cout << "Cat has died." << std::endl;
	delete this->_brain;
}

Cat	&Cat::operator=(const Cat& src)
{
	std::cout << "Cat overload operator (=) has been set." << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		this->_brain = new Brain();
		if (this->_brain == NULL)
		{
			std::cout << "Brain allocation error for Cat overload operator." << std::endl;
			exit(1);
		}
		*this->_brain = *src._brain;
	}
	return (*this);
}
