#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	pressEnter()
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
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m3/Failed Execution (Aform::no signature)\033[0m" << std::endl;
	Bureaucrat	mandy("Mandy", 5);
	ShrubberyCreationForm	formTree("Tree");
	try
	{
		formTree.execute(mandy);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m4/Failed Execution (Bureaucrat::no signature)\033[0m" << std::endl;
	Bureaucrat	billy("Billy", 149);
	std::cout << formTree;
	try
	{
		billy.executeForm(formTree);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m5/Successful Signature\033[0m" << std::endl;
	std::cout << formTree;
	try
	{
		formTree.beSigned(mandy);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m6/Failed Execution (AForm::grade too low)\033[0m" << std::endl;
	std::cout << billy;
	std::cout << formTree;
	try
	{
		formTree.execute(billy);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m7/Failed Execution (Bureaucrat::grade too low)\033[0m" << std::endl;
	std::cout << billy;
	std::cout << formTree;
	try
	{
		billy.executeForm(formTree);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m8/Successful Execution\033[0m" << std::endl;
	try
	{
		formTree.execute(mandy);
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
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m3/Failed Execution (AForm::no signature)\033[0m" << std::endl;
	std::cout << mandy;
	RobotomyRequestForm	formOne("Robot");
	try
	{
		formOne.execute(mandy);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m4/Failed Execution (Bureaucrat::no signature)\033[0m" << std::endl;
	std::cout << mandy;
	std::cout << formOne;
	try
	{
		mandy.executeForm(formOne);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;


// -----------------------------------------------------------------------------

	std::cout << "\033[34m5/Successful Signature\033[0m" << std::endl;
	std::cout << mandy;
	std::cout << formOne;
	try
	{
		formOne.beSigned(mandy);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m6/Failed Execution (AForm::grade too low)\033[0m" << std::endl;
	std::cout << billy;
	std::cout << formOne;
	try
	{
		formOne.execute(billy);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m7/Failed Execution (Bureaucrat::grade too low)\033[0m" << std::endl;
	std::cout << billy;
	std::cout << formOne;
	try
	{
		billy.executeForm(formOne);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m8/Successful Execution\033[0m" << std::endl;
	for(size_t i = 0; i < 6; i++)
	{
		try
		{
			formOne.execute(mandy);
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
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m3/Failed Execution (AForm::no signature)\033[0m" << std::endl;
	std::cout << mandy;
	PresidentialPardonForm	nda("Vacation");
	try
	{
		nda.execute(mandy);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m4/Failed Execution (Bureaucrat::no signature)\033[0m" << std::endl;
	std::cout << mandy;
	std::cout << nda;
	try
	{
		mandy.executeForm(nda);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m5/Successful Signature\033[0m" << std::endl;
	std::cout << mandy;
	std::cout << nda;
	try
	{
		nda.beSigned(mandy);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m6/Failed Execution (AForm::grade too low)\033[0m" << std::endl;
	std::cout << billy;
	std::cout << nda;
	try
	{
		nda.execute(billy);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m7/Failed Execution (Bureaucrat::grade too low)\033[0m" << std::endl;
	std::cout << billy;
	std::cout << nda;
	try
	{
		billy.executeForm(nda);
	}
	catch (AForm::Exception& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;

// -----------------------------------------------------------------------------

	std::cout << "\033[34m8/Successful Execution\033[0m" << std::endl;
	try
	{
		nda.execute(mandy);
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
