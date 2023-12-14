#include "Ice.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Ice::Ice()
{
	this->_type = "ice";
	this->_user = NULL;
	this->_source = NULL;
}

Ice::Ice(const Ice& copy)
{
	*this = copy;
}

Ice::~Ice() {}

Ice	&Ice::operator=(const Ice& src)
{
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

virtual AMateria	*AMateria::clone() const
{
	AMateria*	tmp = new Ice(*this);

	tmp->setUser(NULL);
	tmp->setSource(NULL);
	return (tmp);
}

virtual void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
}
