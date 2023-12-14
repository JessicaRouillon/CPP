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

// Getters & Setters
std::string const	&AMateria::getType() const
{
	return (_type);
}

Character* const	&AMateria::getUser() const
{
	return (_user);
}

MateriaSource* const	&AMateria::getSource() const
{
	return(_source);
}

void	AMateria::setUser(Character* user)
{
	this->_user = user;
}

void	AMateria::setSource(MateriaSource* source)
{
	this->_source = source;
}
