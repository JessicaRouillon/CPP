#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout << "\033[34m1/Construction with grade too low (sign)\033[0m" << std::endl;
	try
	{
		Form	nda("NDA", 0, 50);
	}
	catch (Form::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	
// -----------------------------------------------------------------------------

	std::cout << "\033[34m2/Construction with grade too low (execute)\033[0m" << std::endl;
	try
	{
		Form	nda("NDA", 50, 0);
	}
	catch (Form::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m3/Construction with grade too high (sign)\033[0m" << std::endl;
	try
	{
		Form	nda("NDA", 151, 50);
	}
	catch (Form::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m4/Construction with grade too high (execute)\033[0m" << std::endl;
	try
	{
		Form	nda("NDA", 50, 151);
	}
	catch (Form::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m5/Default Construction\033[0m" << std::endl;
	try
	{
		Form	def;
		std::cout << def << std::endl;
	}
	catch (Form::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m6/Correct Construction\033[0m" << std::endl;
	try
	{
		Form	nda("NDA", 15, 50);
		std::cout << nda << std::endl;
	}
	catch (Form::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m7/Failed Signature\033[0m" << std::endl;
	Bureaucrat	jeff("Jeff", 88);
	Form	nda("NDA", 15, 50);
	try
	{
		nda.beSigned(jeff);
	}
	catch (Form::Exception& e)
	{
		std::cout << e.what();
	}
	jeff.signForm(nda);
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m8/Successful Signature\033[0m" << std::endl;
	Bureaucrat	sam("Sam", 5);
	try
	{
		nda.beSigned(sam);
	}
	catch (Form::Exception& e)
	{
		std::cout << e.what();
	}
	sam.signForm(nda);
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m9/Double Signature\033[0m" << std::endl;
	Bureaucrat	jack("Jack", 10);
	try
	{
		nda.beSigned(jack);
	}
	catch (Form::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34mDestructors\033[0m" << std::endl;
	return (0);
}
