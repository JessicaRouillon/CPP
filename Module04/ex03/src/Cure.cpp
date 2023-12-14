#include "Cure.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Cure::Cure()
{
	this->_type = "cure";
	this->_user = NULL;
	this->_source = NULL;
}

Cure::Cure(const Cure& copy)
{
	*this = copy;
}

Cure::~Cure() {}

Cure	&Cure::operator=(const Cure& src)
{
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

virtual AMateria	*Cure::clone() const
{
	AMateria*	tmp = new Cure(*this);

	tmp->setUser(NULL);
	tmp->setSource(NULL);
	return (tmp);
}

virtual void Ice::use(ICharacter &target)
{
	std::cout << "* heals " << target << "'s wounds *" << std::endl;
}
