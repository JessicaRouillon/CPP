#include "Dog.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Dog::Dog()
{
	std::cout << "Dog is born into the world." << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog& copy)
{
	std::cout << "Copy of Dog is born into the world." << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "Dog has died." << std::endl;
}

Dog	&Dog::operator=(const Dog& src)
{
	std::cout << "Dog overload operator (=) has been set." << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}


/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

void	Dog::makeSound(void) const
{
	std::cout << "The " << this->getType() << " says **WOOOFF** !" << std::endl;
}
