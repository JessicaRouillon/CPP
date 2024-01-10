#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{	
	std::cout << "\033[34m\t================ BUREAUCRAT TESTS ================\033[0m" << std::endl << std::endl;

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

	std::cout << "\033[34m3/Construction with no name\033[0m" << std::endl;
	try
	{
		Bureaucrat	bob("", 42);
	}
	catch (Bureaucrat::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m4/Default Construction\033[0m" << std::endl;
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

	std::cout << "\033[34m5/Correct Construction\033[0m" << std::endl;
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

	std::cout << "\033[34m6/Correct Incrementation\033[0m" << std::endl;
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

	std::cout << "\033[34m7/Correct Decrementation\033[0m" << std::endl;
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

	std::cout << "\033[34m8/Failed Incrementation\033[0m" << std::endl;
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

	std::cout << "\033[34m9/Failed Decrementation\033[0m" << std::endl;
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

// =============================================================================

	std::cout << "\033[34m\t================ FORM TESTS ================\033[0m" << std::endl << std::endl;

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

	std::cout << "\033[34m8/Double Signature\033[0m" << std::endl;
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
