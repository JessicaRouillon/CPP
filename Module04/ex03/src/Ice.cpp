#include "Ice.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Ice::Ice()
{
}

Ice::Ice(const Ice& copy)
{
	*this = copy;
}

Ice::~Ice()
{
}

Ice	&Ice::operator=(const Ice& src)
{
	if (this != &src)
	{
		
	}
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

virtual void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
}