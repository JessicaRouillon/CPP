#include "Cure.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Cure::Cure()
{
	this->_type = "cure";
}

Cure::Cure(const Cure& copy)
{
	*this = copy;
}

Cure::~Cure() {}

Cure	&Cure::operator=(const Cure& src)
{
	// std::cout << "Cure Assignation operator from " << src.getType() << std::endl;
	(void)src;
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

Cure	*Cure::clone() const
{
	Cure*	tmp = new Cure;
	return (tmp);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
