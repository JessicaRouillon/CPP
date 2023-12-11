#include "WrongCat.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

WrongCat::WrongCat()
{
	std::cout << "WrongCat is born into the world." << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy)
{
	std::cout << "Copy of WrongCat is born into the world." << std::endl;
	*this = copy;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat has died." << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat& src)
{
	std::cout << "Cat overload operator (=) has been set." << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}


/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

void	WrongCat::makeSound(void) const
{
	std::cout << "This " << this->getType() << " says **BEEHHH** !" << std::endl;
}
