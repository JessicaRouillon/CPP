#include "AMateria.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

AMateria::AMateria(): _type("")
{
	this->_dropped = false;
}

AMateria::AMateria(std::string const & type): _type(copy._type)
{
	this->_dropped = false;
}

AMateria::AMateria(const AMateria& copy)
{
	*this = copy;
}

AMateria::~AMateria()
{
}

AMateria	&AMateria::operator=(const AMateria& src)
{
	if (this != &src)
	{
		this->_type = src._type;
		this->_dropped = src._dropped;
	}
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

std::string const	&AMateria::getType() const
{
	return (_type);
}

bool const	AMateria::getDropped() const
{
	return (_dropped);
}
