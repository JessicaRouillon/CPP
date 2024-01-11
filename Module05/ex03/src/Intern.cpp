#include "Intern.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Intern::Intern() { std::cout << "Intern has arrived in the office." << std::endl; }

Intern::Intern(const Intern& copy) { (void)copy; }

Intern::~Intern() { std::cout << "Intern has left the office." << std::endl; }

Intern	&Intern::operator=(const Intern& src)
{
	(void)src;
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

// Functions to create the forms

static AForm*	shrub(std::string const target)
{
	AForm*	shrub = new ShrubberyCreationForm(target);
	return (shrub);
}

static AForm*	robot(std::string const target)
{
	AForm*	robot = new RobotomyRequestForm(target);
	return (robot);
}

static AForm*	president(std::string const target)
{
	AForm*	president = new PresidentialPardonForm(target);
	return (president);
}

AForm*		Intern::makeForm(const std::string formName, const std::string formTarget)
{
	AForm*	(*functions[3])(std::string target) = {shrub, robot, president};
	AForm*	ret = NULL;
	std::string		message[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (size_t i = 0; i < 3; i++)
	{
		if (formName == message[i])
			ret = functions[i](formTarget);
	}
	if (ret != NULL)
		std::cout << "Intern creates " << ret->getName() << "." << std::endl;
	else
		throw (Intern::Exception());
	return (ret);
}

const char*		Intern::Exception::what() const throw()
{
	return ("\033[0;31mForm could not ne created by intern.\n\033[0m");
}
