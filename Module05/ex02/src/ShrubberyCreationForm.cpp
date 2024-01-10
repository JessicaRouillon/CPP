#include "ShrubberyCreationForm.hpp"
#include <fstream>

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Default Shrubbery Creation", 145, 137)
{
	this->_target = "Default";
	std::cout << "Default Shrubbery Creation Form has been created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("Shrubbery Creation", 145, 137)
{
	this->_target = target;
	std::cout << "Shrubbery Creation Form for " << target << " has been created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy):
			AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute())
{
	this->_target = copy.getTarget();
	std::cout << "A copy of Shrubbery Creation Form for " << _target
				<< " has been made." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation Form for " << _target << " has been destroyed." << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	std::cout << "Shrubbery Creation Form for " << _target << "'s assignment operator called." << std::endl;
	if (this != &src)
	{
		this->_target = src.getTarget();
	}
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

// Getter

std::string		ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSignedStatus() == false)
		throw (AForm::UnsignedException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (AForm::GradeTooLowException());
	else
	{
		std::string		tree =
		"               ,@@@@@@@,\n"
		"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
		"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
		"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
		"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
		"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
		"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
		"       |o|        | |         | |\n"
		"       |.|        | |         | |\n"
		"    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";

		std::string		outputfile = this->getTarget() + "_shrubbery";
		std::ofstream	output(outputfile.c_str());
		if (output.is_open() == false)
		{
			std::cout << "Error creating file." << std::endl;
			return ;
		}
		output << tree;
	}
}
