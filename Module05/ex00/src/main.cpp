#include "Bureaucrat.hpp"

int	main()
{	
	std::cout << "\033[34m1/Construction with grade too low\033[0m" << std::endl;
	try
	{
		Bureaucrat	bob("Bob", -75);
	}
	catch (Bureaucrat::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m2/Construction with grade too high\033[0m" << std::endl;
	try
	{
		Bureaucrat	bob("Bob", 151);
	}
	catch (Bureaucrat::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m3/Default Construction\033[0m" << std::endl;
	try
	{
		Bureaucrat	ref;
		std::cout << ref << std::endl;
	}
	catch (Bureaucrat::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m4/Correct Construction\033[0m" << std::endl;
	try
	{
		Bureaucrat	bob("Bob", 75);
		std::cout << bob << std::endl;
	}
	catch (Bureaucrat::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m5/Correct Incrementation\033[0m" << std::endl;
	Bureaucrat	jack("Jack", 10);
	try
	{
		jack.incrementGrade();
	}
	catch (Bureaucrat::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m6/Correct Decrementation\033[0m" << std::endl;
	try
	{
		jack.decrementGrade();
	}
	catch (Bureaucrat::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m7/Failed Incrementation\033[0m" << std::endl;
	Bureaucrat	jacky("Jacky", 1);
	try
	{
		jacky.incrementGrade();
	}
	catch (Bureaucrat::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m8/Failed Decrementation\033[0m" << std::endl;
	Bureaucrat	franky("Franky", 150);
	try
	{
		franky.decrementGrade();
	}
	catch (Bureaucrat::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34mDestructors\033[0m" << std::endl;
	return (0);
}
