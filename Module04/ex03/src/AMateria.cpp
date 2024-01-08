#include "AMateria.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

AMateria::AMateria(): _type("")
{
	std::cout << "Abstract Materia has been created." << std::endl;
}

AMateria::AMateria(std::string const & type): _type(type)
{
	std::cout << "Abstract Materia hase been created with type " << type << "." << std::endl;
}

AMateria::AMateria(const AMateria& copy): _type(copy._type)
{
	std::cout << "Abstract Materia Copy has been created." << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Abstract Materia has been destroyed." << std::endl;
}

AMateria	&AMateria::operator=(const AMateria& src)
{
	this->_type = src._type;
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

void	AMateria::use(ICharacter& target)
{
	// (void)target;
	std::cout << "Abstract Materia " << this->getType() << " is used on " << target.getName() << "." << std::endl;
}
