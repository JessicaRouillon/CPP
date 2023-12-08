#include "Dog.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Dog::Dog()
{
	std::cout << "Dog is born into the world." << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		std::cout << "Brain allocation error for Dog." << std::endl;
		exit(1);
	}
}

Dog::Dog(const Dog& copy)
{
	std::cout << "Copy of Dog is born into the world." << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "Dog has died." << std::endl;
	delete this->_brain;
}

Dog	&Dog::operator=(const Dog& src)
{
	std::cout << "Dog overload operator (=) has been set." << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		this->_brain = new Brain();
		if (this->_brain == NULL)
		{
			std::cout << "Brain allocation error for Dog overload operator." << std::endl;
			exit(1);
		}
		*this->_brain = *src._brain;
	}
	return (*this);
}
