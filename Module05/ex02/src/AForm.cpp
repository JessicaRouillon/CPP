#include "AForm.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

AForm::AForm():
		_name("Default"),
		_isSigned(false),
		_gradeToSign(150),
		_gradeToExecute(150)
{
	std::cout << "AForm " << _name << " has been created with default grades 150." << std::endl;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute):
		_name(name),
		_isSigned(false),
		_gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw(AForm::GradeTooHighException());
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw(AForm::GradeTooLowException());
	else
	{
		std::cout << "AForm " << _name << " has been created with grade to sign "
					<< gradeToSign << " and grade to execute "
					<< gradeToExecute << "." << std::endl;
	}
}

AForm::AForm(const AForm& copy):
		_name(copy.getName() + "_copy"),
		_isSigned(copy.getSignedStatus()),
		_gradeToSign(copy.getGradeToSign()),
		_gradeToExecute(copy.getGradeToExecute())
{
	std::cout << "A copy of AForm " << _name << " has been made." << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm " << _name << " has been destroyed." << std::endl;
}

AForm	&AForm::operator=(const AForm& src)
{
	std::cout << "AForm " << _name << "'s assignment operator called." << std::endl;
	if (this != &src)
	{
		this->_isSigned = src.getSignedStatus();
	}
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

// Getters & Setters

std::string		AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSignedStatus() const
{
	return (this->_isSigned);
}

int		AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int		AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void	AForm::setSignedStatus(bool const status)
{
	this->_isSigned = status;
	std::cout << "AForm " << _name << "'s signed status has been set to "
				<< status << "." << std::endl;
}


// Member functions

void	AForm::beSigned(Bureaucrat& ref)
{
	// std::cout << ">> Bureaucrat's grade is " << ref.getGrade() << " and sign grade is " << this->getGradeToSign() << std::endl;
	if (this->getSignedStatus() == true)
		std::cout << "AForm " << _name << " has already been signed." << std::endl;
	else if (ref.getGrade() > this->getGradeToSign())
		throw(AForm::GradeTooLowException());
	else
	{
		this->setSignedStatus(true);
		std::cout << "AForm " << _name << " has been signed by Bureaucrat "
					<< ref.getName() << "." << std::endl;
	}
}


// Exceptions

const char*		AForm::Exception::what() const throw()
{
	return ("\033[0;31mDefault AForm Exception\n\033[0m");
}

const char*		AForm::GradeTooHighException::what() const throw()
{
	return ("\033[0;31mGrade is too high.\n\033[0m");
}

const char*		AForm::GradeTooLowException::what() const throw()
{
	return ("\033[0;31mGrade is too low.\n\033[0m");
}

const char*		AForm::UnsignedException::what() const throw()
{
	return ("\033[0;31mForm is not signed.\n\033[0m");
}


/********************************************************************************/
/*************************** ADDITIONAL FUNCTIONS *******************************/
/********************************************************************************/

// Definition of operator "<<" to output Bureaucrat class instances

std::ostream&	operator<<(std::ostream& output_stream, AForm const &aform)
{
	output_stream << "AForm " << aform.getName() << ", grade to sign is "
				<< aform.getGradeToSign() << " and grade to execute is "
				<< aform.getGradeToExecute() << ". Signed status : " << aform.getSignedStatus()
				<< std::endl;
	return (output_stream);
}
