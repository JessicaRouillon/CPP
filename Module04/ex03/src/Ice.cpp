#include "Ice.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Ice::Ice()
{
	this->_type = "ice";
}

Ice::Ice(const Ice& copy)
{
	*this = copy;
}

Ice::~Ice() {}

Ice	&Ice::operator=(const Ice& src)
{
	// std::cout << "Ice Assignation operator from " << src.getType() << std::endl;
	(void)src;
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

Ice	*Ice::clone() const
{
	Ice*	tmp = new Ice;
	return (tmp);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
