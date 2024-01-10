#include "RobotomyRequestForm.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

RobotomyRequestForm::RobotomyRequestForm(): AForm("Default Robotory Request", 72, 45)
{
	this->_target = "Default";
	std::cout << "Default Robotory Request Form has been created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("Robotory Request", 72, 45)
{
	this->_target = target;
	std::cout << "Robotory Request Form for " << target << " has been created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy):
			AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute())
{
	this->_target = copy.getTarget();
	std::cout << "A copy of Robotory Request Form for " << _target
				<< " has been made." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotory Request Form for " << _target << " has been destroyed." << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	std::cout << "Robotory Request Form for " << _target << "'s assignment operator called." << std::endl;
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

std::string		RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	static size_t i;

	if (this->getSignedStatus() == false)
		throw (AForm::UnsignedException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (AForm::GradeTooLowException());
	else
	{
		std::cout << "* drilling noises *" << std::endl;
		if (i % 2 == 0)
			std::cout << "\033[0;32m" << _target << " has been robotomized." << "\033[0m" << std::endl;
		else
			std::cout << "\033[0;33m" << _target << "'s robotomization failed." << "\033[0m" << std::endl;
		std::cout << std::endl;
		i++;
	}
}
