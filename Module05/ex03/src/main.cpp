#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void    pressEnter()
{
    std::cout << "\033[1;32m" << std::endl << "press ENTER to continue" << "\033[0m" << std::endl;
    std::cin.ignore();
    std::cout << "\033c";
}

int	main()
{
	std::cout << std::endl << "\033[34m============= SHRUBBERY CREATION FORM TESTS =============\033[0m" << std::endl << std::endl;

	std::cout << "\033[34m1/Default Construction\033[0m" << std::endl;
	try
	{
		ShrubberyCreationForm	lol;
		std::cout << lol;
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
		ShrubberyCreationForm	formTree("Tree");
		std::cout << formTree;
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m3/Failed Execution (no signature)\033[0m" << std::endl;
	Bureaucrat	andy("Andy", 5);
	ShrubberyCreationForm	formTree("Tree");
	std::cout << formTree;
	try
	{
		formTree.execute(andy);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m4/Successful Signature\033[0m" << std::endl;
	Bureaucrat	mary("Mary", 5);
	std::cout << formTree;
	try
	{
		formTree.beSigned(mary);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m5/Failed Execution (grade too low)\033[0m" << std::endl;
	Bureaucrat	vanessa("Vanessa", 149);
	try
	{
		formTree.execute(vanessa);
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
		formTree.execute(mary);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << "(See created file in working directory)" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	// =============================================================================

	pressEnter();

	std::cout << std::endl << "\033[34m============= ROBOTOMY REQUEST FORM TESTS =============\033[0m" << std::endl << std::endl;

	std::cout << "\033[34m1/Default Construction\033[0m" << std::endl;
	try
	{
		RobotomyRequestForm	yolo;
		std::cout << yolo;
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
		RobotomyRequestForm	formOne("Robot");
		std::cout << formOne;
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m3/Failed Execution (no signature)\033[0m" << std::endl;
	Bureaucrat	jonny("Jonny", 5);
	RobotomyRequestForm	formOne("Robot");
	std::cout << formOne;
	try
	{
		formOne.execute(jonny);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m4/Successful Signature\033[0m" << std::endl;
	Bureaucrat	sammy("Sammy", 5);
	std::cout << formOne;
	try
	{
		formOne.beSigned(sammy);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m5/Failed Execution (grade too low)\033[0m" << std::endl;
	Bureaucrat	dean("Dean", 149);
	try
	{
		formOne.execute(dean);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m6/Successful Execution\033[0m" << std::endl;
	for(size_t i = 0; i < 6; i++)
	{
		try
		{
			formOne.execute(sammy);
		}
		catch (AForm::Exception& e)
		{
			std::cout << e.what();
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;

// =============================================================================

	pressEnter();

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
		PresidentialPardonForm	nda("Vacation");
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
	PresidentialPardonForm	nda("Vacation");
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
