#include "PresidentialPardonForm.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

PresidentialPardonForm::PresidentialPardonForm(): AForm("Default Presidential Pardon", 25, 5)
{
	this->_target = "Default";
	std::cout << "Default Presidential Pardon Form has been created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("Presidential Pardon", 25, 5)
{
	this->_target = target;
	std::cout << "Presidential Pardon Form for " << target << " has been created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy):
			AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute())
{
	this->_target = copy.getTarget();
	std::cout << "A copy of Presidential Pardon Form for " << _target
				<< " has been made." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon Form for " << _target << " has been destroyed." << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	std::cout << "Presidential Pardon Form for " << _target << "'s assignment operator called." << std::endl;
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

std::string		PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSignedStatus() == false)
		throw (AForm::UnsignedException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (AForm::GradeTooLowException());
	else
		std::cout << "\033[0;32m" << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << "\033[0m" << std::endl;
}
