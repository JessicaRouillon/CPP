#include "Intern.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Intern::Intern()
{
	std::cout << "Intern has arrived in the office." << std::endl;
}

Intern::Intern(const Intern& copy) :
{
	std::cout << "Default Intern has been copied (but there is nothing to copy)." << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern has left the office." << std::endl;
}

Intern	&Intern::operator=(const Intern& src)
{
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

AForm*		Intern::makeForm(const std::string formName, const std::string formTarget)
{
	AForm*	form("");

	if (formName.is_empty() == true)
		throw (Intern::Exception());
	else
		std::cout << "Intern creates " << 
	return (form);
}

const char*		Intern::Exception::what() const throw()
{
	return ("\033[0;31mForm Name cannot be empty.\n\033[0m");
}
