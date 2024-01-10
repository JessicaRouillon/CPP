#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	std::cout << std::endl << "\033[34m============= PRESIDENTIAL PARDON FORM TESTS =============\033[0m" << std::endl << std::endl;

	std::cout << "\033[34m1/Default Construction\033[0m" << std::endl;
	try
	{
		PresidentialPardonForm	def;
		std::cout << def;
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m2/Custom Construction\033[0m" << std::endl;
	try
	{
		PresidentialPardonForm	nda("N42");
		std::cout << nda;
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m3/Failed Execution (no signature)\033[0m" << std::endl;
	Bureaucrat	jeff("Jeff", 5);
	PresidentialPardonForm	nda("N42");
	std::cout << nda;
	try
	{
		nda.execute(jeff);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m4/Successful Signature\033[0m" << std::endl;
	Bureaucrat	sam("Sam", 5);
	std::cout << nda;
	try
	{
		nda.beSigned(sam);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m5/Failed Execution (grade too low)\033[0m" << std::endl;
	Bureaucrat	jack("Jack", 149);
	try
	{
		nda.execute(jack);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m6/Successful Execution\033[0m" << std::endl;
	try
	{
		nda.execute(sam);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34mDestructors\033[0m" << std::endl;
	return (0);
}
