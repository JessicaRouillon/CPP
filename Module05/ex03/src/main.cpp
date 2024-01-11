#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	std::cout << "\033[34mConstructors\033[0m" << std::endl;
	
	Intern	intern;
	AForm*	shrub;
	AForm*	robot;
	AForm*	president;
	AForm*	other;

	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34mShrubbery creation test\033[0m" << std::endl;
	shrub = intern.makeForm("shrubbery creation", "Bender");
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34mRobotomization request test \033[0m" << std::endl;
	robot = intern.makeForm("robotomy request", "Fender");
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34mPresidential pardon test \033[0m" << std::endl;
	president = intern.makeForm("presidential pardon", "Zender");
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34mFailed test\033[0m" << std::endl;
	try
	{
		other = intern.makeForm("unemployment notice", "Hender");
		delete other;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

// -----------------------------------------------------------------------------

	std::cout << "\033[34mDestructors\033[0m" << std::endl;
	delete shrub;
	delete robot;
	delete president;
	return (0);
}
